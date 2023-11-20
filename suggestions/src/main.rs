use std::time::Instant;

type SuggestionFn = fn(&str, &[&str]) -> SuggestionResult;

struct SuggestionResult {
    /// index to the array
    id: usize,

    /// diff value
    diff: u32,
}

#[derive(Default, Debug)]
struct BitHistogram {
    w0: u64,
    w1: u64,
    w2: u64,
    w3: u64,
}

impl BitHistogram {
    pub fn new(s: &str) -> Self {
        let mut h = BitHistogram::default();
        h.add(s);

        return h;
    }

    pub fn add(&mut self, s: &str) {
        for b in s.as_bytes() {
            self.add_byte(*b);
        }
    }

    fn add_byte(&mut self, b: u8) {
        let bit: u64 = 1 << (b & 0x3f);

        match b >> 6 {
            0 => self.w0 |= bit,
            1 => self.w1 |= bit,
            2 => self.w2 |= bit,
            3 => self.w3 |= bit,
            _ => unreachable!(),
        }
    }

    pub fn diff(&self, h1: &Self) -> u32 {
        let d0 = (self.w0 ^ h1.w0).count_ones();
        let d1 = (self.w1 ^ h1.w1).count_ones();
        let d2 = (self.w2 ^ h1.w2).count_ones();
        let d3 = (self.w3 ^ h1.w3).count_ones();

        return d0 + d1 + d2 + d3;
    }
}

fn suggestion1(s: &str, patterns: &[&str]) -> SuggestionResult {
    let h = BitHistogram::new(s);

    let mut result = SuggestionResult {
        id: 0,
        diff: u32::MAX,
    };

    for (id, s1) in patterns.iter().enumerate() {
        let h1 = BitHistogram::new(s1);

        let diff = h.diff(&h1);
        if diff < result.diff {
            result.id = id;
            result.diff = diff;
        }
    }

    return result;
}

struct ByteHistogram {
    hist: [u32; 128],
}

impl ByteHistogram {
    pub fn new() -> Self {
        Self { hist: [0; 128] }
    }

    pub fn add(&mut self, s: &str) {
        for b in s.as_bytes() {
            self.hist[*b as usize] += 1;
        }
    }

    pub fn reset(&mut self) {
        for i in 0..self.hist.len() {
            self.hist[i] = 0;
        }
    }

    pub fn diff(&self, h1: &Self) -> u32 {
        let mut res: u32 = 0;

        for i in 0..self.hist.len() {
            let c1 = self.hist[i];
            let c2 = h1.hist[i];

            res += c1.abs_diff(c2);
        }

        return res;
    }
}

fn suggestion2(s: &str, patterns: &[&str]) -> SuggestionResult {
    let mut h = ByteHistogram::new();
    h.add(s);

    let mut result = SuggestionResult {
        id: 0,
        diff: u32::MAX,
    };

    let mut h1 = ByteHistogram::new();
    for (id, s1) in patterns.iter().enumerate() {
        h1.reset();
        h1.add(s1);

        let diff = h.diff(&h1);
        if diff < result.diff {
            result.id = id;
            result.diff = diff;
        }
    }

    return result;
}

fn mutate(s: &str) -> Vec<String> {
    let mut res = Vec::<String>::new();

    let n = s.len();
    // 1. remove i-th letter
    for i in 0..n {
        let s1 = format!("{}{}", &s[..i], &s[i + 1..]);
        res.push(s1);
    }

    let lower_ascii = "abcdefghijklmnopqestuvwxyz";

    for letter in lower_ascii.chars() {
        // 2. set i-th letter to fixed upper case one
        for i in 0..n {
            let s1 = format!("{}{}{}", &s[..i], letter, &s[i + 1..]);
            res.push(s1);
        }

        // 3. insert extra letter
        for i in 0..n {
            let s1 = format!("{}{}{}", &s[..i], letter, &s[i..]);
            res.push(s1);
        }

        res.push(format!("{}{}", s, letter));
    }

    // 4. swap letters
    let mut bytes = s.as_bytes().to_vec();
    for i in 0..n {
        for j in i + 1..n {
            let tmp = bytes[i];
            bytes[i] = bytes[j];
            bytes[j] = tmp;

            res.push(std::str::from_utf8(&bytes).unwrap().to_string());

            let tmp = bytes[i];
            bytes[i] = bytes[j];
            bytes[j] = tmp;
        }
    }

    return res;
}

fn levenstain_distance(str1: &str, str2: &str) -> u32 {
    let s1 = str1.as_bytes();
    let s2 = str2.as_bytes();

    let n = s1.len();
    let m = s2.len();
    let mut v0 = Vec::<u32>::with_capacity(n + 1);
    for i in 0..n + 1 {
        v0.push(i as u32);
    }

    let mut v1: Vec<u32> = vec![0; n + 1];

    const DELETION_COST: u32 = 1;
    const INSERTION_COST: u32 = 1;
    const SUBSTITUTION_COST: u32 = 1;

    for j in 0..m {
        v1[0] = (j + 1) as u32;
        for i in 0..n {
            let deletion_cost = v0[i + 1] + DELETION_COST;
            let insertion_cost = v1[i] + INSERTION_COST;
            let substitution_cost = if s1[i] == s2[j] {
                v0[i]
            } else {
                v0[i] + SUBSTITUTION_COST
            };

            v1[i + 1] = std::cmp::min(
                std::cmp::min(deletion_cost, insertion_cost),
                substitution_cost,
            );
        }

        std::mem::swap(&mut v0, &mut v1);
    }

    return v0[n];
}

fn suggestion3(s: &str, patterns: &[&str]) -> SuggestionResult {
    let mut result = SuggestionResult {
        id: 0,
        diff: u32::MAX,
    };

    for (id, s1) in patterns.iter().enumerate() {
        let diff = levenstain_distance(s, s1);
        if diff < result.diff {
            result.id = id;
            result.diff = diff;
        }
    }

    return result;
}

struct SummaryItem {
    input: String,
    cases: usize,
    misses: usize,
    ratio: f64,
}

struct Summary(Vec<SummaryItem>);

impl Summary {
    fn dump(&self) {
        for item in &self.0 {
            println!(
                "{:20}: cases={:4}, misses={:4} hit rate = {:6.2}%",
                item.input,
                item.cases,
                item.misses,
                100.0 * item.ratio
            );
        }

        println!("average ratio: {:.2}%", 100.0 * self.average_ratio());
    }

    fn average_ratio(&self) -> f64 {
        let mut sum: f64 = 0.0;

        for item in &self.0 {
            sum += item.ratio;
        }

        return sum / (self.0.len() as f64);
    }
}

fn test(name: &str, set: &[&str], suggestion: SuggestionFn, verbose: bool) -> Summary {
    let start = Instant::now();
    let res = test_aux(set, suggestion, verbose);
    let duration = start.elapsed();

    println!("{}: {:?}", name, duration);

    return res;
}

fn test_aux(set: &[&str], suggestion: SuggestionFn, verbose: bool) -> Summary {
    let mut summary = Vec::<SummaryItem>::with_capacity(set.len());
    for (id, s) in set.iter().enumerate() {
        let cases = mutate(s);
        let n = cases.len();
        let mut misses: usize = 0;
        for case in cases {
            let result = suggestion(case.as_str(), &set);
            if result.id != id {
                if verbose {
                    if misses == 0 {
                        println!("{}:", s);
                    }
                    println!("\t{} => {} [diff={}]", case, set[result.id], result.diff);
                }
                misses += 1;
            }
        }

        let item = SummaryItem {
            input: s.to_string(),
            cases: n,
            misses,
            ratio: ((n - misses) as f64) / (n as f64),
        };
        summary.push(item);
    }

    return Summary(summary);
}

fn test_all(name: &str, set: &[&str], verbose: bool, show_summary: bool) {
    println!("{}", name);
    let s1 = test("Levenshtein distance", &set, suggestion3, verbose);
    if show_summary {
        s1.dump();
    }

    let s2 = test("BitHistogram", &set, suggestion1, verbose);
    if show_summary {
        s2.dump();
    }

    let s3 = test("ByteHistogram", &set, suggestion2, verbose);
    if show_summary {
        s3.dump();
    }

    collate(&s1, &s2, &s3, set);
}

fn collate(s1: &Summary, s2: &Summary, s3: &Summary, set: &[&str]) {
    fn sep() {
        println!(
            "+--------------+-------+--------+---------+--------+---------+--------+---------+"
        );
    }
    for i in 0..set.len() {
        let word = set[i];
        let item1 = &s1.0[i];
        let item2 = &s2.0[i];
        let item3 = &s3.0[i];

        sep();
        println!(
            "| {word:12} | {:5} | {:6} | {:6.2}% | {:6} | {:6.2}% | {:6} | {:6.2}% |",
            item1.cases,
            item1.misses,
            100.0 * item1.ratio,
            item2.misses,
            100.0 * item2.ratio,
            item2.misses,
            100.0 * item3.ratio
        );
    }

    sep();
}

fn main() {
    let gitcommands = [
        "clone", "init", "add", "mv", "restore", "rm", "bisect", "diff", "grep", "log", "show",
        "status", "branch", "commit", "merge", "rebase", "reset", "switch", "tag", "fetch", "pull",
        "push",
    ];

    let pythonstrmethods = [
        "capitalize",
        "casefold",
        "center",
        "count",
        "encode",
        "endswith",
        "expandtabs",
        "find",
        "format",
        "format_map",
        "index",
        "isalnum",
        "isalpha",
        "isascii",
        "isdecimal",
        "isdigit",
        "isidentifier",
        "islower",
        "isnumeric",
        "isprintable",
        "isspace",
        "istitle",
        "isupper",
        "join",
        "ljust",
        "lower",
        "lstrip",
        "maketrans",
        "partition",
        "removeprefix",
        "removesuffix",
        "replace",
        "rfind",
        "rindex",
        "rjust",
        "rpartition",
        "rsplit",
        "rstrip",
        "split",
        "splitlines",
        "startswith",
        "strip",
        "swapcase",
        "title",
        "translate",
        "upper",
        "zfill",
    ];

    let verbose = true;
    let show_summary = true;

    test_all("git commands", &gitcommands, verbose, show_summary);
    test_all("str methods", &pythonstrmethods, verbose, show_summary);
}
