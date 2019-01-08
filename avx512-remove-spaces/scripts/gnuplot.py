import sys
from parse import load

def main():
    input_path   = sys.argv[1]
    data_path    = sys.argv[2]
    gnuplot_path = sys.argv[3]
    png_path     = sys.argv[4]
    cpu_name     = sys.argv[5]

    with open(input_path) as f:
        data = load(f)
        keys = sorted(data[1].keys())

    with open(data_path, 'wt') as f:
        gnuplot_data(f, data)

    with open(gnuplot_path, 'wt') as f:
        gnuplot_script(f, keys, data_path, png_path, cpu_name)


def gnuplot_data(f, data):
    for cardinality in xrange(1, 64+1):
        measurements = data[cardinality]

        f.write('%d' % cardinality)
        for k in sorted(measurements):
            meas = measurements[k]
            cycles = meas.best
            f.write(' %0.3f' % cycles)

        f.write('\n')


def gnuplot_generate_plots(keys, data_path):
    result = []
    for index, key in enumerate(keys):
        title = key
        param = {
            'data'   : data_path,
            'column' : index + 2,
            'title'  : title,
        }

        result.append(GNUPLOT_PLOT % param)

    return result


def gnuplot_script(file, keys, data_path, png_path, cpu_name):
    param = {
        'plots' : ', '.join(gnuplot_generate_plots(keys, data_path)),
        'data'  : data_path,
        'png'   : png_path,
        'cpu'   : cpu_name,
    }

    file.write(GNUPLOT % param)


GNUPLOT_PLOT='"%(data)s" using 1:%(column)d with lines title "%(title)s" noenhanced'

GNUPLOT="""
set terminal png size 800,600
set output "%(png)s"

set title "Microbenchmark on %(cpu)s"
set xlabel "number of whitespaces in a 64 byte block"
set ylabel "CPU cycles/input byte (best)"
set yrange [0:]
set xrange [0:64]
set xtics 4
set key left

plot %(plots)s
"""

if __name__ == '__main__':
    main()

