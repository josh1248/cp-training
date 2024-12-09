# https://open.kattis.com/problems/bank
from sys import stdin
import heapq

def algo(s, ins):
    times = [[] for _ in range(s[1] + 1)]
    for c, t in ins:
        times[t].append(c)
    
    out = 0
    pq = []
    # work backwards and be greedy
    t = s[1]
    while t >= 0:
        for c in times[t]:
            heapq.heappush(pq, -c)
        
        if len(pq) > 0:
            out -= heapq.heappop(pq)
        t -= 1
    
    print(out)
        


def main():
    args = []
    s = [int(i) for i in stdin.readline().strip().split(" ")]
    for _ in range(s[0]):
        args.append([int(i) for i in stdin.readline().strip().split(" ")])
    algo(s, args)

main()