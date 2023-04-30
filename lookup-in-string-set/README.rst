Sample programs for article `Modern perfect hashing for strings`__

__ http://0x80.pl/notesen/2023-04-30-lookup-in-strings.html

Usage
--------------------------------------------------

The whole testing/benchmarking is based on **datasets**
subdirectory. All ``*.txt`` files placed in that subdir
are supposed to contain plain list of keywords.

To recreate Makefile run::

    $ python3 mkfile.py

If there's no Go 1.20 available, it's possible to run::

    $ python3 mkfile.py --without-go

Running test and benchmarks::

    $ make unittest && ./unittest
    $ make benchmark && ./benchmark

Note that prior running benchmarks, it's needed to create
test files in **testdata** subdir. It may take some time.

Likewise compilation may take some time.
