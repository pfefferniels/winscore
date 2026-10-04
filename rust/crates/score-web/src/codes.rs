//! Names of the item codes (P1), from the headings of Smith's WinScore help
//! pages `code1` … `code18`.

pub fn code_name(code: i32) -> Option<&'static str> {
    Some(match code {
        1 => "Note",
        2 => "Rest",
        3 => "Clef",
        4 => "Line, hairpin",
        5 => "Slur, tie, ending",
        6 => "Beam",
        7 => "Trill, ottava, pedal",
        8 => "Staff",
        9 => "Symbol",
        10 => "Number, rehearsal letter",
        11 => "User .DRW item",
        12 => "Box, circle, guitar grid",
        14 => "Barline, brace, bracket",
        15 => "PostScript import",
        16 => "Text",
        17 => "Key signature",
        18 => "Meter",
        _ => return None,
    })
}
