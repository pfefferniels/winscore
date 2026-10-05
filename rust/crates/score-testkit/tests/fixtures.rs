use score_render::ItemId;
use score_testkit::{
    assert_codes_match_fixture, assert_matches_fixture, display_from_json, display_to_json,
    fixtures_dir, load_all, restrict, Fixture,
};

#[test]
fn every_fixture_loads_and_matches_itself() {
    let fixtures = load_all(&fixtures_dir()).unwrap();
    assert!(
        fixtures.len() > 100,
        "only {} fixtures found",
        fixtures.len()
    );
    fixtures
        .iter()
        .filter(|f| f.meta.valid)
        .for_each(|f| assert_matches_fixture(f, &f.display));
}

#[test]
fn every_input_parses() {
    load_all(&fixtures_dir()).unwrap().iter().for_each(|f| {
        let file = f.input().unwrap();
        if let Some(items) = f.meta.items {
            assert_eq!(
                file.items.len() as u32,
                items + f.meta.dropped_items.len() as u32,
                "{}: item count differs from the engine's",
                f.name
            );
        }
    });
}

#[test]
fn json_round_trips_through_display_list() {
    load_all(&fixtures_dir()).unwrap().iter().for_each(|f| {
        let again = display_from_json(&display_to_json(&f.display)).unwrap();
        assert_eq!(again, f.display, "{}", f.name);
    });
}

#[test]
fn every_element_of_a_valid_fixture_has_its_item() {
    load_all(&fixtures_dir())
        .unwrap()
        .iter()
        .filter(|f| f.meta.valid)
        .for_each(|f| {
            let items = f.input().unwrap().items.len() as u32;
            let sources = f
                .display
                .shapes
                .iter()
                .map(|s| s.source)
                .chain(f.display.texts.iter().map(|t| t.source));
            sources.for_each(|source| {
                let ItemId(i) =
                    source.unwrap_or_else(|| panic!("{}: element without item", f.name));
                assert!(i < items, "{}: item {i} of {items}", f.name);
            });
        });
}

#[test]
fn codes_can_be_compared_on_their_own() {
    let fixture = Fixture::named("code14-p5-final").unwrap();
    let barline = restrict(&fixture.display, |ItemId(i)| i == 4);
    assert_eq!(barline.shapes.len(), 3);
    assert!(barline.texts.is_empty());
    assert_codes_match_fixture(&fixture, &barline, &[14]);
}
