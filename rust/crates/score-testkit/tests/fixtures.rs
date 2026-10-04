use score_testkit::{assert_matches_fixture, display_from_json, display_to_json, fixtures_dir, load_all};

#[test]
fn every_fixture_loads_and_matches_itself() {
    let fixtures = load_all(&fixtures_dir()).unwrap();
    assert!(fixtures.len() > 100, "only {} fixtures found", fixtures.len());
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
                items,
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
