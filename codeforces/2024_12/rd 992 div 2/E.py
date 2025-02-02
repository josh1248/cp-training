from collections import defaultdict

def algo(ins):
    # with 1 child with even turn number: E(X) = 0.5(E(x) + 2) + 0.5(E(above 2)) + 2
    # simplified; E(X) = 4 + E(above 2)
    # generally, for n children:
    # simplified: E(X) = 2n + 2 + E(above 2) for n children
    # time savings is 2n

    # if parent is the solution: E(X) = 1/n(1) + (n-1) / n(E(X) + 2)
    # simplified: E(X) = 2n + 1
    # time savings is 2n

    # idea: store time savings per node, capture in max-heap, take top p time savings
    vertices, queries = ins[0][0], ins[0][1]

    # store parent, neighbours, and added E(V) if even turn starts on that vertex
    graph = [[None, set(), 0] for _ in range(vertices + 1)]
    for i in range(vertices - 1):
        u, v = ins[i + 1]
        graph[u][1].add(v)
        graph[v][1].add(u)

    # DFS to set parent nodes
    def dfs(n, prev):
        node = graph[n]
        # parent already set
        if node[0]:
            return
        else:
            # link to prev parent
            node[0] = prev

            # spread dfs
            for nxt in node[1]:
                dfs(nxt, n)
            
            # check if immediate parent is 1
            if n == 1:
                pass
            elif node[0] == 1:
                node[2] = 2 * (len(node[1]) - 1) + 1
            else:
                node[2] = 2 * (len(node[1]) - 1) + 2
    
    dfs(1, 1)

    def f(start, coins):
        if start == 1:
            return 0
        
        path = []
        curr = start
        length = 0

        while curr != 1:
            path.append(graph[curr][2])

            tmp = graph[curr][0]
            if tmp == 1:
                length += 1
                curr = tmp
            else:
                length += 2
                curr = graph[tmp][0]
        
        if coins >= len(path):
            return length
        elif coins == 0:
            return sum(path)
        else:
            path.sort()
            return sum(path) - sum(path[-(coins):]) + 2 * coins - (1 if length % 2 == 1 else 0)
    
    for i in range(queries):
        start, coins = ins[i + vertices]
        if start == 1:
            print(0)
        else:
            print((1 + f(graph[start][0], coins)) % 998244353)


def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        args.append([int(i) for i in input().split(" ")])
        for _ in range(sum(args[0]) - 1):
            args.append([int(i) for i in input().split(" ")])
        algo(args)

main()