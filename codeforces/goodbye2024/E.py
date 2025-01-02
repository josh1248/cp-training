from sys import stdin
read = lambda: stdin.readline().strip()

def algo(n, args):
    # aron will win in 2 scenarios:
    # 1: p is not a leaf node, q is a leaf node
    # calculate no. of leaf nodes * no. of non-leaf nodes
    # 2: dist(p to leaf node) >= 2, dist(q to leaf node) == 2, and Nora's move pulls q 1 distance to a leaf node.
    # for each vertex, check neighbours. if dist(to leaf node) == 1, check depth 2+ nodes "upstream".
    # call recursively.
    graph = {i: [] for i in range(1, n + 1)}
    depths = {i: 99 for i in range(1, n + 1)}
    for i, j in args:
        graph[i].append(j)
        graph[j].append(i)
    
    leaves = 0
    res = 0
    leaf_adjacents = set()
    for i in graph:
        if len(graph[i]) == 1:
            leaves += 1
            leaf_adjacents.add(graph[i][0])
    return leaves * (n - leaves)


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        n = int(read())
        args = []
        for _ in range(n - 1):
            args.append([int(i) for i in read().split(" ")])
        print(algo(n, args))

main()