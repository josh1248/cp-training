# https://open.kattis.com/problems/wheresmyinternet
# Time: 00:14

from sys import stdin
read = lambda: stdin.readline().strip()

def algo(a, b, ins):
    uf = {i: i for i in range(1, a + 1)}

    def find(x):
        if uf[x] != x:
            uf[x] = find(uf[x])   
        return uf[x]

    def union(x, y):
        sx, sy = find(x), find(y)
        if sx <= sy:
            uf[sy] = sx
        else:
            uf[sx] = sy
 
    for x, y in ins:
        union(x, y)
    
    flag = False
    for i in range(1, a + 1):
        if find(i) != 1:
            flag = True
            print(i)

    if not flag:
        print("Connected")
    

def main():
    args = []
    a, b = [int(i) for i in read().split()]
    for _ in range(b):
        args.append([int(i) for i in read().split()])
    algo(a, b, args)

main()