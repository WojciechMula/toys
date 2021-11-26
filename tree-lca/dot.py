from node import Node


def parse(file):
    labels = set()
    edges = set()
    for k, line in enumerate(file):
        line = line.strip()
        if not line:
            continue

        if '->' in line:
            source, target = parse_edge(line)
            edges.add((source, target))
            labels.add(source)
            labels.add(target)

    nodes = {}
    for label in labels:
        nodes[label] = Node(label)

    for (source, target) in edges:
        nodes[source].add(nodes[target])

    root = None
    for node in nodes.values():
        if node.is_root():
            assert root is None
            root = node

    assert root is not None

    return (root, nodes)


def parse_edge(line):
    tmp = line.split('->')
    if len(tmp) != 2:
        raise ValueError(f"wrong edge spec: {line}")

    return (tmp[0].strip(), tmp[1].strip())


def save(file, nodes, attributes):
    def writeln(s):
        file.write(s)
        file.write('\n')

    writeln('digraph {')
    for label, attrib in attributes.items():
        writeln(f'\t{label} [{attrib}]')

    for node in nodes.values():
        source = node.label
        for child in node.children:
            target = child.label
            writeln(f'\t{source} -> {target}')

    writeln('}')
