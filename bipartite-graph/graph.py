def load(path):
    graph = {}
    pairs = []
    with open(path, 'r') as f:
        lines = []
        for line in f:
            line = line.strip()
            if line == '' or line.startswith('#') or line.startswith('//'):
                continue

            lines.append(line)
    
    if lines[0] != "graph {":
        raise ValueError("the first line has to be 'graph {', got: '%s'" % lines[0])
    else:
        del lines[0]

    if lines[-1] != "}":
        raise ValueError("the last line has to be '}', got: '%s'" % lines[-1])
    else:
        del lines[-1]
        
    for line in lines:
        tmp = line.split()
        if len(tmp) != 3:
            raise ValueError("wrong syntax '%s'" % line)
        if tmp[1] != '--':
            raise ValueError("wrong syntax '%s'" % line)

        node1, node2 = tmp[0], tmp[2]
        assert node1 != node2
        pairs.append((node1, node2))
        graph[node1] = set()
        graph[node2] = set()

    for node1, node2 in pairs:
        graph[node1].add(node2)
        graph[node2].add(node1)

    return graph
