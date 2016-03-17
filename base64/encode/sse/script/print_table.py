from sys   import argv
from table import Table
from utils import unicode_bar
from data  import Data
from codecs import open

def main():

    with open(argv[1], 'rt') as f:
        data = Data(f)

    table = Table()
    table.set_header(["procedure", "time [s]", "speedup", ""])

    reference_time = None
    for name, time in data:
        if reference_time is None:
            reference_time = time

        speedup = reference_time/time

        time    = '%0.5f' % time
        bar     = unicode_bar(speedup * 10)
        speedup = '%0.2f' % speedup
        table.add_row([name, time, speedup, bar])

    path = 'table.txt'
    with open(path, 'wt', encoding='utf-8') as f:
        f.write(unicode(table))

    print "%s created" % path

main()
