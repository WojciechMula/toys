set terminal png medium size 800,600

set output "avgcmp.png"

set title "average comparisions - key distribution is shaped by function x^exponent"
set logscale x
set xlabel "exponent"
set ylabel "count"

plot "avgcmp.results" using 1:2 with lines title "binary search", \
     "avgcmp.results" using 1:3 with lines title "interpolation search"

