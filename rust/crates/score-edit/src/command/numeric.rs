//! Parameter changes typed as numbers in edit mode (WinScore help, "Editing
//! the Music"): `p v` pairs, `p00 v` or `/p v` relative, `p0000 q` or
//! `//p q` transfer, `-p` sign change, `a -9999 b` zeroing a range.

use crate::command::parse::Token;
use crate::error::EditError;
use crate::params::{Draft, MAX_PARAM};

const ZERO_RANGE: f32 = -9999.0;
const RELATIVE_FACTOR: u32 = 100;
const TRANSFER_FACTOR: u32 = 10_000;

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum ParamOp {
    Set { n: usize, value: f32 },
    Add { n: usize, delta: f32 },
    Copy { to: usize, from: usize },
    Negate { n: usize },
    Zero { from: usize, to: usize },
}

impl ParamOp {
    pub fn apply(self, draft: &mut Draft) {
        match self {
            ParamOp::Set { n, value } => draft.set(n, value),
            ParamOp::Add { n, delta } => draft.add(n, delta),
            ParamOp::Copy { to, from } => draft.set(to, draft.get(from)),
            ParamOp::Negate { n } => draft.set(n, -draft.get(n)),
            ParamOp::Zero { from, to } => draft.zero(from, to),
        }
    }
}

/// A parameter number as typed: whole and within 1..=MAX_PARAM.
pub fn param_number(value: f32) -> Result<usize, EditError> {
    let n = value as usize;
    if value.fract() == 0.0 && (1..=MAX_PARAM).contains(&n) {
        Ok(n)
    } else {
        Err(EditError::NoSuchParam(value))
    }
}

/// `p` of a plain pair, decoded: `600` is relative P6, `50000` transfer to P5.
fn pair(p: f32, value: f32) -> Result<ParamOp, EditError> {
    if p.fract() != 0.0 || p < 0.0 {
        return Err(EditError::NoSuchParam(p));
    }
    let whole = p as u32;
    if whole >= TRANSFER_FACTOR && whole % TRANSFER_FACTOR == 0 {
        Ok(ParamOp::Copy { to: param_number((whole / TRANSFER_FACTOR) as f32)?, from: param_number(value)? })
    } else if whole >= RELATIVE_FACTOR && whole % RELATIVE_FACTOR == 0 {
        Ok(ParamOp::Add { n: param_number((whole / RELATIVE_FACTOR) as f32)?, delta: value })
    } else {
        Ok(ParamOp::Set { n: param_number(p)?, value })
    }
}

/// The operations of an all-numeric line, or `None` if the line holds a word.
pub fn param_ops(tokens: &[Token]) -> Option<Result<Vec<ParamOp>, EditError>> {
    if tokens.iter().any(|t| matches!(t, Token::Word(_))) {
        return None;
    }
    Some(ops(tokens))
}

fn ops(tokens: &[Token]) -> Result<Vec<ParamOp>, EditError> {
    if let [Token::Number(p)] = tokens {
        if *p < 0.0 {
            return Ok(vec![ParamOp::Negate { n: param_number(-p)? }]);
        }
    }
    let mut ops = Vec::new();
    let mut rest = tokens;
    while let Some((first, tail)) = rest.split_first() {
        let value = tail.first().and_then(Token::number);
        let (op, used) = match (first, value) {
            (Token::Number(from), Some(ZERO_RANGE)) => {
                let to = tail.get(1).and_then(Token::number);
                let op = ParamOp::Zero { from: param_number(*from)?, to: to.map_or(Ok(MAX_PARAM), param_number)? };
                (op, if to.is_some() { 3 } else { 2 })
            }
            (Token::Number(p), value) => (pair(*p, value.unwrap_or(0.0))?, 2),
            (Token::Relative(p), value) => (ParamOp::Add { n: param_number(*p)?, delta: value.unwrap_or(0.0) }, 2),
            (Token::Transfer(p), Some(q)) => (ParamOp::Copy { to: param_number(*p)?, from: param_number(q)? }, 2),
            (Token::Transfer(p), None) => return Err(EditError::NoSuchParam(*p)),
            (Token::Word(w), _) => return Err(EditError::UnknownCommand(w.clone())),
        };
        ops.push(op);
        rest = &rest[used.min(rest.len())..];
    }
    Ok(ops)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::command::parse::tokens;

    fn run(line: &str, params: &[f32]) -> Vec<f32> {
        let mut draft = Draft::new(params);
        param_ops(&tokens(line)).unwrap().unwrap().into_iter().for_each(|op| op.apply(&mut draft));
        (1..=draft.len()).map(|n| draft.get(n)).collect()
    }

    const NOTE: [f32; 7] = [1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0];

    #[test]
    fn pairs_set_parameters() {
        assert_eq!(run("5 20 7 2", &NOTE), [1.0, 1.0, 100.0, 6.0, 20.0, 0.0, 2.0]);
    }

    #[test]
    fn a_lone_number_sets_zero() {
        assert_eq!(run("3 50 4", &NOTE), [1.0, 1.0, 50.0, 0.0, 10.0, 0.0, 1.0]);
    }

    #[test]
    fn relative_and_transfer_forms() {
        assert_eq!(run("600 5", &NOTE)[5], 5.0);
        assert_eq!(run("/3 -10.5", &NOTE)[2], 89.5);
        assert_eq!(run("50000 4", &NOTE)[4], 6.0);
        assert_eq!(run("//8 4", &NOTE)[7], 6.0);
    }

    #[test]
    fn negation_and_zeroing() {
        assert_eq!(run("-5", &NOTE)[4], -10.0);
        let long = [1.0, 1.0, 100.0, 6.0, 10.0, 1.0, 0.0, 3.0, 12.0, 4.0, 5.0, 6.0, 7.0];
        assert_eq!(run("7 -9999 10", &long)[6..], [0.0, 0.0, 0.0, 0.0, 5.0, 6.0, 7.0]);
        assert_eq!(run("9 -9999", &long)[7..], [3.0, 0.0, 0.0, 0.0, 0.0, 0.0]);
    }

    #[test]
    fn parameter_numbers_are_checked() {
        assert_eq!(param_ops(&tokens("0 5")), Some(Err(EditError::NoSuchParam(0.0))));
        assert_eq!(param_ops(&tokens("2.5 1")), Some(Err(EditError::NoSuchParam(2.5))));
        assert_eq!(param_ops(&tokens("NOTE 1")), None);
    }
}
