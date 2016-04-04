from sys   import argv
from table import Table
from utils import unicode_bar
from data  import Data
from codecs import open
import os.path

def convert(csv_path):
    with open(csv_path) as f:
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

    def get_path():
        basename = os.path.splitext(os.path.basename(csv_path))[0]
        return basename + ".txt"

    path = get_path()
    with open(path, 'wt', encoding='utf-8') as f:
        f.write(unicode(table))

    print "%s created" % path

def main():

    for path in argv[1:]:
        print "processing %s..." % path
        convert(path)


if __name__ == '__main__':
    main()
