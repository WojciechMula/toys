Microbenchmarks
--------------------------------------------------------------------------------

.. image:: results.png


Performance tests (only Zach's procedure)
--------------------------------------------------------------------------------

::

    tom-sawyer.txt
    scalar           : ..........       1286 us
    AVX512VBMI (Zach): ..........         58 us (22 x)

    moby-dick.txt
    scalar           : ..........       3744 us
    AVX512VBMI (Zach): ..........        178 us (21 x)

    sherlock.txt
    scalar           : ..........       1847 us
    AVX512VBMI (Zach): ..........         81 us (22 x)

    census-income.data
    scalar           : ..........     161613 us
    AVX512VBMI (Zach): ..........      17079 us (9.4 x)

    weather_sept_85.csv
    scalar           : ..........     117209 us
    AVX512VBMI (Zach): ..........      12326 us (9.5 x)
