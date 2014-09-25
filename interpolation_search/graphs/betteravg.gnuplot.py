def read(file):
    
    for line in file:
        field = line.split()

        exp    = float(field[0])
        better = int(field[-1])
        if better:
            color = "#00ff00"
        else:
            color = "#ff0000"
        
        yield "x**%0.2f lt rgb '%s'" % (exp, color)

if __name__ == '__main__':
    import sys
    from os.path import dirname, join
    
    path = join(dirname(__file__), 'betteravg.gnuplot.pattern')
    with open(path) as f:
        gnuplot = f.read()

    plot = ','.join(item for item in read(sys.stdin))

    print gnuplot.replace('__PLOT__', plot);
