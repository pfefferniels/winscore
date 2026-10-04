//! Splitting a SCORE command line into tokens.
//!
//! Tokens are separated by blanks or commas. A token is a number, a
//! parameter number marked `/p` (relative change) or `//p` (transfer), or a
//! word. `R10`-style words with a count attached are split by the command
//! tables, which know which words end in digits of their own (`RH32`, `BEAM2`).

#[derive(Debug, Clone, PartialEq)]
pub enum Token {
    Number(f32),
    /// `/p`: add the next number to parameter p.
    Relative(f32),
    /// `//p`: copy parameter q (the next number) into parameter p.
    Transfer(f32),
    Word(String),
}

impl Token {
    pub fn number(&self) -> Option<f32> {
        match self {
            Token::Number(n) => Some(*n),
            _ => None,
        }
    }

    pub fn word(&self) -> Option<&str> {
        match self {
            Token::Word(w) => Some(w),
            _ => None,
        }
    }
}

/// A number as SCORE accepts it: `5`, `-.5`, `12.25`, `+3`.
pub fn number(text: &str) -> Option<f32> {
    let digits = text.strip_prefix(['+', '-']).unwrap_or(text);
    let well_formed = digits.chars().any(|c| c.is_ascii_digit())
        && digits.chars().all(|c| c.is_ascii_digit() || c == '.')
        && digits.matches('.').count() <= 1;
    well_formed.then(|| text.parse().ok()).flatten()
}

fn token(text: &str) -> Token {
    if let Some(n) = text.strip_prefix("//").and_then(number) {
        Token::Transfer(n)
    } else if let Some(n) = text.strip_prefix('/').and_then(number) {
        Token::Relative(n)
    } else if let Some(n) = number(text) {
        Token::Number(n)
    } else {
        Token::Word(text.to_owned())
    }
}

pub fn tokens(line: &str) -> Vec<Token> {
    line.split([' ', ',', '\t']).filter(|t| !t.is_empty()).map(token).collect()
}

/// Splits a count off the end of a word: `R10` gives `("R", 10)`, `U` gives `("U", None)`.
pub fn split_count(word: &str) -> (&str, Option<f32>) {
    let start = word.find(|c: char| c.is_ascii_digit() || c == '.' || c == '-').unwrap_or(word.len());
    match number(&word[start..]) {
        Some(n) if start > 0 => (&word[..start], Some(n)),
        _ => (word, None),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn numbers_words_and_marked_parameters() {
        assert_eq!(
            tokens("/19 -.5, //5 4 NOTE"),
            vec![
                Token::Relative(19.0),
                Token::Number(-0.5),
                Token::Transfer(5.0),
                Token::Number(4.0),
                Token::Word("NOTE".into())
            ]
        );
    }

    #[test]
    fn words_with_signs_stay_words() {
        assert_eq!(tokens("ENH+1 -A + CR-"), ["ENH+1", "-A", "+", "CR-"].map(|w| Token::Word(w.into())));
    }

    #[test]
    fn number_forms() {
        assert_eq!(number(".8"), Some(0.8));
        assert_eq!(number("12.25"), Some(12.25));
        assert_eq!(number("+3"), Some(3.0));
        assert_eq!(number("-9999"), Some(-9999.0));
        assert_eq!(number("."), None);
        assert_eq!(number("1.2.3"), None);
        assert_eq!(number("5e3"), None);
    }

    #[test]
    fn counts_split_off_words() {
        assert_eq!(split_count("R10"), ("R", Some(10.0)));
        assert_eq!(split_count("U"), ("U", None));
        assert_eq!(split_count("L.5"), ("L", Some(0.5)));
        assert_eq!(split_count("10"), ("10", None));
    }
}
