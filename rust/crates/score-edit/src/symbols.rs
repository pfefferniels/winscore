//! The library symbols a code-9 item can show (P5), for a symbol picker:
//! every symbol of WinScore's bundled libraries, named after WinScore's
//! own list `scorlib/symblist.txt` where it has an entry.

use score_render::symbols::SymbolLibrary;

const SYMBOL_LIST: &[u8] = include_bytes!("../../../../assets/scorlib/symblist.txt");
/// Symbol numbers run up to 5099 (`LB5090.DRW` would be the last file).
const LAST_SYMBOL: i32 = 5099;

/// One library symbol: the number P5 takes and a name to show.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct LibrarySymbol {
    pub number: i32,
    pub name: String,
}

/// `NNNN   name` lines of the symbol list (Latin-1).
fn listed_names() -> Vec<(i32, String)> {
    let text: String = SYMBOL_LIST.iter().map(|&b| char::from(b)).collect();
    text.lines()
        .filter_map(|line| {
            let (number, name) = line.split_at_checked(4)?;
            let number = number.parse::<i32>().ok()?;
            let name = name.trim();
            (!name.is_empty()).then(|| (number, name.to_owned()))
        })
        .collect()
}

/// Every symbol the bundled libraries draw, in number order.
pub fn library_symbols() -> Vec<LibrarySymbol> {
    let library = SymbolLibrary::bundled();
    let listed = listed_names();
    (0..=LAST_SYMBOL)
        .filter_map(|number| {
            let symbol = library.symbol(number)?;
            let name = listed
                .iter()
                .find(|(n, _)| *n == number)
                .map_or_else(|| symbol.name.trim().to_owned(), |(_, name)| name.clone());
            Some(LibrarySymbol { number, name })
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn symbols_carry_winscores_names() {
        let symbols = library_symbols();
        let accent = symbols.iter().find(|s| s.number == 22).unwrap();
        assert_eq!(accent.name, "accent");
        assert!(symbols.len() > 300, "{}", symbols.len());
        assert!(symbols.windows(2).all(|w| w[0].number < w[1].number));
    }
}
