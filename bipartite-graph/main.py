import sys
from graph import load

def main():
    for path in sys.argv[1:]:
        graph = load(path)
        res = bipartite(graph)
        if res:
            set1, set2 = res
            set1 = list(sorted(set1))
            set2 = list(sorted(set2))
            print("%s: %s, %s" % (path, set1, set2))
        else:
            print("%s: not a bipartite graph" % path)


def bipartite(graph):
    set1 = set()
    set2 = set()
    seen = set()

    queue = list(graph.keys())[:1]
    set1.add(queue[0])
    while queue:
        node = queue.pop(0)
        if node in seen:
            continue

        if node in set1:
            current  = set1
            opposite = set2
            seen.add(node)
        elif node in set2:
            current  = set2
            opposite = set1
            seen.add(node)
        else:
            queue.append(node)
            continue

        for child in graph[node]:
            if child in current:
                return None
            elif child in opposite:
                pass
            else:
                opposite.add(child)

            queue.append(child)


    if len(seen) != len(graph):
        # not all nodes visited, it's a multigraph
        return None
        

    return (set1, set2)

if __name__ == '__main__':
    main()
