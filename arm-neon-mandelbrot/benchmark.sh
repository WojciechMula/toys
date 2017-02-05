make fractal
for i in `seq 10`
do
    ./fractal $1 --dry-run | grep " us"
done
