# Summing floating point numbers

The following approaches are tested:

* **naive summing** -- sum numbers as they are given in the input;
* **sorting** -- the input numbers are sorted, then added;
* **grouped** -- for each exponent value (2048 for `float64`)
  keep separate accumulator; in the end, sum accumulators;
* **Kahan** -- https://en.wikipedia.org/wiki/Kahan_summation_algorithm.

Comparison of precision (`go test -v`):

```
smoke_test.go:27: sorted  = 500381.7613767000
smoke_test.go:28: naive   = 500381.7613767174 (diff: 0.0000000174)
smoke_test.go:29: kahan   = 500381.7613767002 (diff: 0.0000000002)
smoke_test.go:30: grouped = 500381.7613767001 (diff: 0.0000000001)
```

Performance (`go test -run XYZ -bench`):

```
BenchmarkNaive-4         1369432           910.6 ns/op  8785.48 MB/s
BenchmarkSorted-4           8956        129305.0 ns/op    61.87 MB/s
BenchmarkGrouped-4         63828         19479.0 ns/op   410.70 MB/s
BenchmarkKahan-4         1399851           854.7 ns/op  9360.43 MB/s
```
