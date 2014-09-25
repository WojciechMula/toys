set terminal png medium size 800,600

set output "speed.png"

set title "running time - key distribution is shaped by function x^exponent"
set logscale x
set xlabel "exponent"
set ylabel "time"

plot "speed.results" using 1:2 with lines title "binary search", \
     "speed.results" using 1:3 with lines title "interpolation search"
