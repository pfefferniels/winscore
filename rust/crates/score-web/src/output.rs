//! The page as it goes to paper: rendered for print (no staff numbers or
//! other screen aids) as an SVG document, which the app downloads for
//! export and puts in the page for the browser's print.

use score_format::MusFile;
use score_render::svg::{to_svg, SvgOptions, Viewport};
use score_render::{render, DisplayList, Document, Medium, Options};
use wasm_bindgen::prelude::*;

use crate::Score;

const PRINT: Options = Options { medium: Medium::Print, staff_numbers: false };

fn print_list(file: &MusFile) -> (DisplayList, Viewport) {
    let doc = Document::with_options(file, PRINT);
    (render(&doc), Viewport::paper(doc.page.paper))
}

/// The printed page as an SVG document the size of the paper.
pub fn page_svg(file: &MusFile) -> String {
    let (list, paper) = print_list(file);
    to_svg(&list, &SvgOptions::new(paper))
}

#[wasm_bindgen]
impl Score {
    /// The printed page as an SVG document the size of the paper, for
    /// export and print. Its text names the app's bundled faces first
    /// (`web/src/svg-fonts.ts` embeds them in exported files).
    #[wasm_bindgen(js_name = exportSvg)]
    pub fn export_svg(&self) -> String {
        page_svg(self.0.file())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    fn mozart() -> MusFile {
        let path = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../WINSCORE 5.01/winscore/mozart.mus");
        MusFile::parse(&std::fs::read(path).unwrap()).unwrap()
    }

    #[test]
    fn print_leaves_out_staff_numbers() {
        let file = mozart();
        let screen = render(&score_render::Document::new(&file));
        let (print, _) = print_list(&file);
        let staff_number_runs = |list: &DisplayList| list.texts.iter().filter(|t| t.font == "Helvetica-Narrow").count();
        assert!(staff_number_runs(&screen) > 0);
        assert_eq!(staff_number_runs(&print), 0);
        assert!(!page_svg(&file).contains("'WS Heros Cn'"));
    }

    #[test]
    fn svg_is_paper_sized() {
        let svg = page_svg(&mozart());
        assert!(svg.starts_with("<svg"));
        assert!(svg.contains("width=\"8.5in\""), "{}", &svg[..200]);
    }

    #[test]
    fn svg_draws_with_scores_pen_and_the_bundled_faces() {
        let svg = page_svg(&mozart());
        assert!(svg.contains(" stroke-width=\"26.67\" stroke-linejoin=\"round\""), "{}", &svg[..400]);
        // The title, "SONATA in C MAJOR", is one text element (the engine
        // places no spaces).
        let mut texts = svg.split("</text>").filter_map(|t| t.rsplit_once('>')).map(|(_, text)| text.replace(' ', ""));
        assert!(texts.any(|text| text == "SONATAinCMAJOR"));
        assert!(svg.contains("font-family=\"'WS Termes', "));
        assert!(svg.contains("font-family=\"'WS Chorus', "));
    }
}
