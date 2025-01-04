class Entry:
    def __init__(self, url, ip):
        self.url = url
        self.ip  = ip

def parse_line(line, filter):
    F = line.split()

    code = F[-2]
    ip   = F[0]
    url  = F[6]

    if filter(url, ip, code):
        return Entry(url, ip)


def parse_log(file):

    freq = {}

    def filter(url, ip, code):
        
        if code != "200":
            return False

        if not ("articles" in url or "notesen" in url or "notespl" in url):
            return False

        if not url.endswith(".html"):
            return False

        return True

    for line in file:
        d = parse_line(line, filter)
        if d is None:
            continue

        if d.url in freq:
            freq[d.url].append(d.ip)
        else:
            freq[d.url] = [d.ip]

    return freq


def main():
    
    import sys

    d = {}

    for path in sys.argv[1:]:
        with open(path, 'r') as f:
            d.update(parse_log(f))

    L = []
    all_visitors = []
    for url, ips in d.iteritems():
        all_visitors.extend(ips)
        visitors = len(set(ips))
        visits   = len(ips)
        L.append((url, visits, visitors))

    L.sort(key=lambda item: item[2], reverse=True) # by visits

    for url, visits, visitors in L:
        print "%-6d %-6d %s" % (visits, visitors, url)

    total_visits   = len(all_visitors)
    total_visitors = len(set(all_visitors))
    print "%-6d %-6d" % (total_visits, total_visitors)

if __name__ == '__main__':
    main()
