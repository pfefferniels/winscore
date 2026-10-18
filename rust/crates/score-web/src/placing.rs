//! From page points to SCORE's own coordinates for new items: staff number,
//! P3 and P4.
//!
//! Page x is 150 × P3 plus the page offset of the staff's side (verso or
//! recto), page y is the staff's internal y plus the same offset
//! (`score_render::page`). Only staves defined by a code-8 item count.

use score_format::MusFile;
use score_render::page::{page_offset, P3_UNIT, RECTO_SHIFT};
use score_render::staff::Staff;
use score_render::Document;

/// Where a new item goes: staff, P3 and P4.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Place {
    pub staff: i32,
    pub p3: f32,
    pub p4: f32,
}

fn is_recto_x(x: f64) -> bool {
    x >= f64::from(RECTO_SHIFT)
}

fn p3_at(staff: i32, x: f64) -> f32 {
    ((x - f64::from(page_offset(staff).x)) / P3_UNIT) as f32
}

fn mid_y(staff: &Staff) -> f64 {
    f64::from(staff.mid + page_offset(staff.number).y)
}

/// Defined staves on the page side of page x.
fn staves_at(file: &MusFile, x: f64) -> Vec<Staff> {
    let staves = Document::new(file).staves;
    staves.defined().filter(|s| score_render::page::is_recto(s.number) == is_recto_x(x)).copied().collect()
}

/// The staff nearest to page point (`x`, `y`) and the P3 and P4 the point
/// has on it, P3 to 0.01 and P4 to whole scale steps.
pub fn place_at(file: &MusFile, x: f64, y: f64) -> Option<Place> {
    let staff = staves_at(file, x).into_iter().min_by(|a, b| (mid_y(a) - y).abs().total_cmp(&(mid_y(b) - y).abs()))?;
    let internal_y = y - f64::from(page_offset(staff.number).y);
    let p4 = ((internal_y - f64::from(staff.level0)) / staff.scale_step()).round() as f32;
    let p3 = (p3_at(staff.number, x) * 100.0).round() / 100.0;
    Some(Place { staff: staff.number, p3, p4 })
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    fn mozart() -> MusFile {
        let path = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../assets/samples/mozart.mus");
        MusFile::parse(&std::fs::read(path).unwrap()).unwrap()
    }

    fn staff_mid(file: &MusFile, number: i32) -> f64 {
        mid_y(&Document::new(file).staves.get(number))
    }

    #[test]
    fn a_point_on_a_staff_names_that_staff() {
        let file = mozart();
        let place = place_at(&file, 2000.0 + 150.0 * 50.0, staff_mid(&file, 3)).unwrap();
        assert_eq!(place.staff, 3);
        assert_eq!(place.p3, 50.0);
        let staff = Document::new(&file).staves.get(3);
        let mid_line_step = (f64::from(staff.mid - staff.level0) / staff.scale_step()).round() as f32;
        assert_eq!(place.p4, mid_line_step);
    }
}
