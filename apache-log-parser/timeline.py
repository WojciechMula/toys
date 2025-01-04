class Entry:
    def __init__(self, url, ip, date):
        self.url  = url
        self.ip   = ip
        self.date = date

def get_data(input):
    """
    input:  [dd/Mnt/yyyy:hh:mm:ss]"
    output: (yyyy,mm,dd)
    """

    months = {
        'Jan': 1,
        'Feb': 2,
        'Mar': 3,
        'Apr': 4,
        'May': 5,
        'Jun': 6,
        'Jul': 7,
        'Aug': 8,
        'Sep': 9,
        'Oct': 10,
        'Nov': 11,
        'Dec': 12
    }

    field   = input[1:]
    field   = field.split(':', 1)[0]
    d, m, y = field.split('/')

    d = int(d)
    m = months[m]
    y = int(y)

    return (y, m, d)


def parse_line(line, filter):
    F = line.split()

    code = F[-2]
    ip   = F[0]
    url  = F[6]

    if filter(url, ip, code):
        return Entry(url, ip, get_data(F[3]))


def parse_log(file, query):

    freq = {}

    def global_filter(url, ip, code):
        
        if code != "200":
            return False

        if not ("articles" in url or "notesen" in url or "notespl" in url):
            return False

        if not url.endswith(".html"):
            return False

        return True


    def filter(url, ip, code):
        return global_filter(url, ip, code) and (query in url)


    for line in file:
        d = parse_line(line, filter)
        if d is None:
            continue

        if d.date in freq:
            freq[d.date].append(d.ip)
        else:
            freq[d.date] = [d.ip]

    return freq


def main():
    
    import sys

    data = {}

    url = sys.argv[1]

    for path in sys.argv[2:]:
        with open(path, 'r') as f:
            data.update(parse_log(f, url))

    if not data:
        print "wrong query"
        return

    max_count = float(max(map(len, data.itervalues())))

    def bar(count, width=60):
        n = int(width*count/max_count)
        return '=' * n

    print url
    total = 0
    for key in sorted(data.keys()):
        y, m, d = key
        count = len(data[key])
        print "%04d-%02d-%02d: %5d %s" % (y, m, d, count, bar(count))

        total += count

    print "total: %d" % (total,)

if __name__ == '__main__':
    main()
