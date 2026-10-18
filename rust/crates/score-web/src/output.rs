//! The page as it goes to paper: rendered for print (no staff numbers or
//! other screen aids), as SVG or as a display list for the browser's print.

use score_format::MusFile;
use score_render::svg::{to_svg, SvgOptions, Viewport};
use score_render::{render, DisplayList, Document, Medium, Options};
use wasm_bindgen::prelude::*;

use crate::{EncodedList, Score};

const PRINT: Options = Options { medium: Medium::Print, staff_numbers: false, ..Options::REFINED };

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
    /// The printed page as an SVG document the size of the paper.
    #[wasm_bindgen(js_name = exportSvg)]
    pub fn export_svg(&self) -> String {
        page_svg(self.0.file())
    }

    /// The page rendered for print, without screen aids, for the browser's print.
    #[wasm_bindgen(js_name = renderPrint)]
    pub fn render_print(&self) -> EncodedList {
        EncodedList::from(&print_list(self.0.file()).0)
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
        let screen = render(&crate::drawn(&file));
        let (print, _) = print_list(&file);
        let staff_number_runs = |list: &DisplayList| list.texts.iter().filter(|t| t.font == "Helvetica-Narrow").count();
        assert!(staff_number_runs(&screen) > 0);
        assert_eq!(staff_number_runs(&print), 0);
    }

    #[test]
    fn svg_is_paper_sized() {
        let svg = page_svg(&mozart());
        assert!(svg.starts_with("<svg"));
        assert!(svg.contains("width=\"8.5in\""), "{}", &svg[..200]);
    }
}
