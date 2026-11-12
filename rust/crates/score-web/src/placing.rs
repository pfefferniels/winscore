//! From page points to SCORE's own coordinates for new items: staff number,
//! P3 and P4.
//!
//! Page x is 150 × P3 plus the page offset of the staff's side (verso or
//! recto), page y is the staff's internal y plus the same offset
//! (`score_render::page`). Only staves defined by a code-8 item count.

use score_format::MusFile;
use score_render::page::{page_offset, LAST_VERSO_STAFF, P3_UNIT, RECTO_SHIFT};
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

/// Number and P4 of a new staff whose middle line lies nearest page height
/// `y`, on the page side of `x`. SCORE numbers staves from the bottom of the
/// page up, each with a place on a default grid that P4 moves it from: the
/// new staff takes the number whose default place is nearest, so that P4
/// stays small, as long as that number is free and keeps the numbers rising
/// up the page; otherwise the one above the highest (below the lowest when
/// it goes under them all).
pub fn new_staff_at(file: &MusFile, x: f64, y: f64) -> (i32, f32) {
    let first = if is_recto_x(x) { LAST_VERSO_STAFF + 1 } else { 1 };
    let last = first + LAST_VERSO_STAFF - 1;
    let defined = staves_at(file, x);
    let fits = |n: i32| {
        defined.iter().all(|s| match s.number.cmp(&n) {
            std::cmp::Ordering::Less => mid_y(s) < y,
            std::cmp::Ordering::Greater => mid_y(s) > y,
            std::cmp::Ordering::Equal => false,
        })
    };
    let nearest = (first..=last).min_by(|&a, &b| {
        let (da, db) = ((mid_y(&Staff::default_for(a)) - y).abs(), (mid_y(&Staff::default_for(b)) - y).abs());
        da.total_cmp(&db)
    });
    let highest = defined.iter().map(|s| s.number).max();
    let lowest = defined.iter().map(|s| s.number).min();
    let below_all = defined.iter().all(|s| mid_y(s) > y);
    let number = match nearest.filter(|&n| fits(n)) {
        Some(n) => n,
        None => match (lowest, highest) {
            (Some(low), _) if below_all && low > first => low - 1,
            (_, Some(high)) => high + 1,
            _ => first,
        },
    };
    let staff = Staff::default_for(number);
    let p4 = ((y - mid_y(&staff)) / staff.scale_step()).round() as f32;
    (number, p4)
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

    /// `file` with a staff item of `number` moved by `p4`, and that staff's middle line.
    fn with_staff(file: &MusFile, number: i32, p4: f32) -> f64 {
        let mut moved = file.clone();
        moved.items.push(score_format::Item::new([8.0, number as f32, 0.0, p4].into_iter().map(score_format::Word::from).collect()));
        staff_mid(&moved, number)
    }

    #[test]
    fn a_new_staff_above_the_others_is_numbered_above_them_where_it_is_put() {
        let file = mozart();
        let highest = Document::new(&file).staves.highest().unwrap();
        let wanted = staff_mid(&file, highest) + 3000.0;
        let (number, p4) = new_staff_at(&file, 5000.0, wanted);
        assert!(number > highest);
        let step = Staff::default_for(number).scale_step();
        assert!((with_staff(&file, number, p4) - wanted).abs() <= step / 2.0 + 1.0);
        assert!(p4.abs() < 18.0, "near its place on the grid: P4 {p4}");
    }

    #[test]
    fn a_staff_on_an_empty_page_takes_the_number_of_its_place() {
        let empty = MusFile::empty();
        let top = mid_y(&Staff::default_for(17));
        let (number, p4) = new_staff_at(&empty, 5000.0, top + 100.0);
        assert_eq!((number, p4), (17, 1.0));
        let (low, _) = new_staff_at(&empty, 5000.0, mid_y(&Staff::default_for(1)) - 5000.0);
        assert_eq!(low, 1);
    }
}
