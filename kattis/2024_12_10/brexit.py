# https://open.kattis.com/problems/brexit
from sys import stdin
from collections import deque, defaultdict
read = lambda: stdin.readline().strip()

def algo(c, p, x, l, args):
    lq = deque([l])
    graph = defaultdict(lambda: [])
    counts = defaultdict(lambda: 0)
    for c1, c2 in args:
        graph[c1].append(c2)
        graph[c2].append(c1)
    
    left = set()
    while lq:
        c = lq.popleft()
        if c in left:
            continue
        left.add(c)
        if c == x:
            print("leave")
            return

        for n in graph[c]:
            counts[n] += 1
            if counts[n] * 2 >= len(graph[n]):
                lq.append(n)
    print("stay")
    

        

def main():
    args = []
    c, p, x, l = [int(i) for i in read().split()]
    for _ in range(p):
        args.append([int(i) for i in read().split()])
    algo(c, p, x, l, args)

main()