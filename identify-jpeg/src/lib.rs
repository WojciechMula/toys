/// Function `identify` check whether the chunk of data looks like JPEG structure.
/// If so, then return recognized image dimension (in pixels), the number of color
/// components and component precision.
pub fn identify(bytes: &[u8]) -> Option<ImageDetails> {
    let mut bytes = bytes;

    let mut offset = 0;
    while !bytes.is_empty() {
        let chunk = Chunk::from_bytes(bytes)?;

        if offset == 0 && !matches!(chunk.typ, ChunkType::StartOfImage) {
            // The StartOfImage chunk has to be the very first one
            return None;
        }

        const CHUNK_HEADER_SIZE: usize = 2;
        const CHUNK_SIZE_LEN: usize = 2;

        if matches!(
            chunk.typ,
            ChunkType::Baseline | ChunkType::Progressive | ChunkType::ExtendedSequential
        ) {
            const MIN_BYTES: usize = 7;
            if bytes.len() < MIN_BYTES + CHUNK_HEADER_SIZE + CHUNK_SIZE_LEN {
                return None;
            }

            let bytes = &bytes[CHUNK_HEADER_SIZE + CHUNK_SIZE_LEN..];

            return Some(ImageDetails {
                precision: bytes[0],
                height: mk_word(bytes[1], bytes[2]),
                width: mk_word(bytes[3], bytes[4]),
                components: bytes[5],
            });
        }

        let skip = CHUNK_HEADER_SIZE + chunk.size as usize;
        if skip > bytes.len() {
            // encountered some garbage
            break;
        }

        bytes = &bytes[skip..];
        offset += skip;
    }

    None
}

pub struct ImageDetails {
    pub width: u16,
    pub height: u16,
    pub components: u8,
    pub precision: u8,
}

#[derive(Debug)]
struct Chunk {
    pub typ: ChunkType,
    pub size: u16,
}

impl Chunk {
    pub fn from_bytes(bytes: &[u8]) -> Option<Self> {
        if bytes.len() < 2 {
            return None;
        }

        if bytes[0] != 0xff {
            return None;
        }

        let typ = ChunkType::from_byte(bytes[1])?;
        let size = if typ.is_dataless() {
            0
        } else {
            mk_word(bytes[2], bytes[3])
        };

        Some(Chunk { typ, size })
    }
}

#[inline]
fn mk_word(b0: u8, b1: u8) -> u16 {
    let b0 = b0 as u16;
    let b1 = b1 as u16;

    (b0 << 8) | b1
}

#[derive(Debug)]
enum ChunkType {
    Comment,
    Baseline,
    ExtendedSequential,
    Progressive,
    HuffmanTable,
    Exif,
    IccProfile,
    QuantizationTable,
    RestartInterval,
    StartOfImage,
    EndOfImage,
    Restart,
    Jfif,
}

impl ChunkType {
    fn from_byte(b: u8) -> Option<Self> {
        match b {
            0xfe => Some(Self::Comment),
            0xc0 => Some(Self::Baseline),
            0xc1 => Some(Self::ExtendedSequential),
            0xc2 => Some(Self::Progressive),
            0xc4 => Some(Self::HuffmanTable),
            0xdb => Some(Self::QuantizationTable),
            0xd8 => Some(Self::StartOfImage),
            0xd9 => Some(Self::EndOfImage),
            0xdd => Some(Self::RestartInterval),
            0xe0 => Some(Self::Jfif),
            0xe1 => Some(Self::Exif),
            0xe2 => Some(Self::IccProfile),
            0xd0..=0xd7 => Some(Self::Restart),
            _ => None,
        }
    }

    #[inline]
    const fn is_dataless(&self) -> bool {
        matches!(
            self,
            ChunkType::StartOfImage | ChunkType::EndOfImage | ChunkType::Restart
        )
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::fs::read;
    use std::fs::read_dir;
    use std::path::Path;

    #[test]
    fn test_identify() -> Result<(), std::io::Error> {
        let rootdir = Path::new("images");
        assert!(
            rootdir.exists(),
            "directory/link to directory '{}' does not exist",
            rootdir.display()
        );

        for entry in read_dir(&rootdir)? {
            let entry = entry?;
            let path = entry.path();
            if !path.is_file() {
                continue;
            }

            let bytes = read(&path)?;

            print!("{}: ", path.display());
            if let Some(details) = identify(&bytes) {
                println!(
                    "{} x {} pixels, components={} precision={}",
                    details.width, details.height, details.components, details.precision
                );
            } else {
                println!("not a JPEG image");
            }
        }

        Ok(())
    }
}
