/// One 32-bit word of a SCORE file.
///
/// Almost every word is an IEEE single-precision float, but a few hold integer
/// bit patterns (the serial number in the trailer) and text items embed raw
/// characters. Keeping the bits makes reading and writing lossless.
#[derive(Clone, Copy, PartialEq, Eq, Hash, Default)]
pub struct Word(u32);

impl Word {
    pub const fn from_bits(bits: u32) -> Self {
        Self(bits)
    }

    pub fn from_f32(value: f32) -> Self {
        Self(value.to_bits())
    }

    pub const fn bits(self) -> u32 {
        self.0
    }

    pub fn as_f32(self) -> f32 {
        f32::from_bits(self.0)
    }

    pub fn to_le_bytes(self) -> [u8; 4] {
        self.0.to_le_bytes()
    }
}

impl std::fmt::Debug for Word {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.as_f32())
    }
}

impl From<f32> for Word {
    fn from(value: f32) -> Self {
        Self::from_f32(value)
    }
}
