from sys import stdin
from functools import cache

def algo(ins):
    graph = {}
    for l in ins:
        if len(l) == 2:
            graph[l[0]] = (l[1] == "favourably")
        else:
            graph[l[0]] = l[1:]
    
    @cache
    def dfs(n):
        if graph[n] == True:
            return 1
        elif graph[n] == False:
            return 0
        else:
            return sum(dfs(nxt) for nxt in graph[n])
        
    print(dfs('1'))
            



def main():
    n = int(stdin.readline().strip())
    for _ in range(n):
        m = int(stdin.readline())

        args = []
        for _ in range(m):
            args.append([i for i in stdin.readline().strip().split(" ")])
        algo(args)
main()