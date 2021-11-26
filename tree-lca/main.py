import dot
from node import Node


def depth(node: Node):
    n = 0
    while node:
        node = node.parent
        n += 1

    return n


def lowest_common_ancestor(node1: Node, node2: Node):
    # 1. find the depths of both nodes
    d1 = depth(node1)
    d2 = depth(node2)

    # 2. move up the deeper node (if any)
    if d1 > d2:
        for i in range(d1 - d2):
            node1 = node1.parent
    elif d2 > d1:
        for i in range(d2 - d1):
            node2 = node2.parent

    # 3. now both node pointers are at the same depth
    assert depth(node1) == depth(node2)

    # 4. it's sufficient to move up both until they reach the common parent
    while node1 != node2:
        node1 = node1.parent
        node2 = node2.parent

    return node1


def main():
    with open('example.dot', 'rt') as f:
        root, nodes = dot.parse(f)

    tmp = list(nodes.values())
    n = len(nodes)
    results = []
    for i in range(n):
        A = tmp[i]
        for j in range(i+1, n):
            B = tmp[j]
            C = lowest_common_ancestor(A, B)

            results.append((A, B, C))

    for A, B, C in results:
        path = f'lca_{A.label}-{B.label}.dot'
        attr = {
            A.label: 'style="filled", color="lightblue"',
            B.label: 'style="filled", color="lightgreen"',
            C.label: 'style="filled", color="hotpink"',
        }

        with open(path, 'wt') as f:
            dot.save(f, nodes, attr)


if __name__ == '__main__':
    main()
