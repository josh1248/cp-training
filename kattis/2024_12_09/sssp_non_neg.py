from sys import stdin
from collections import defaultdict
import heapq

def algo(s, e, q):
    graph = {i: [] for i in range(s[0])}

    for edges in e:
        # distances before node so that pq can maintain heap variant on first
        graph[edges[0]].append((edges[2], edges[1]))
    
    estimates = defaultdict(lambda: float('inf'))

    pq = [(0, s[3])]
    while pq:
        d, n = heapq.heappop(pq)

        if d >= estimates[n]:
            continue
    
        estimates[n] = d

        for nxt in graph[n]:
            p1, n1 = nxt
            heapq.heappush(pq, (p1 + d, n1))
    
    for t in q:
        if (e := estimates[t[0]]) == float('inf'):
            print("Impossible")
        else:
            print(e)

def main():
    
    while True:
        start = [int(i) for i in stdin.readline().strip().split(" ")]

        if start == [0, 0, 0, 0]:
            break

        edges = []
        for _ in range(start[1]):
            edges.append([int(i) for i in stdin.readline().strip().split(" ")])
        
        queries = []
        for _ in range(start[2]):
            queries.append([int(i) for i in stdin.readline().strip().split(" ")])
        
        algo(start, edges, queries)

main()