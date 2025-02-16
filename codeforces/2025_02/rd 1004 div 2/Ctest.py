from sys import stdin
from functools import cache
read = lambda: stdin.readline().strip()
from collections import deque
 
@cache
def algo(s: str):
    if s.count('7') > 0:
        return 0
 
    # find minimum turns to convert target digit (from rightmost) to 7
    def bfs(original, t):
        q = deque()
        hits = set()
        q.append([original, t, 0])
        while q:
            i, t, turns = q.popleft()
            if i in hits:
                continue
            if (i // (10**t) % 10 == 7):
                return turns
            hits.add(i)
            q.append([i + 10 ** t - 1, t, turns + 1])
            q.append([i + 10 ** (t - 1) - 1, t, turns + 1])
        
    res = 999
    for r in range(len(s) + 1):
        res = min(res, bfs(int(s), r))
    
    return res
 
 
total_inputs = int(read())
for _ in range(total_inputs):
    print(algo(read()))