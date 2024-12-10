# https://open.kattis.com/problems/trainpassengers
from sys import stdin
read = lambda: stdin.readline().strip()

def algo(c, ins):
    curr = 0
    for l, e, s in ins:
        curr -= l
        if curr < 0:
            print("impossible");return

        curr += e
        if curr > c:
            print("impossible");return
        
        if s > 0 and curr != c:
            print("impossible");return
    
    if curr == 0 and ins[-1][2] == 0:
        print("possible")
    else:
        print("impossible")
    

def main():
    args = []
    c, n = [int(i) for i in read().split()]
    for _ in range(n):
        args.append([int(i) for i in read().split()])
    algo(c, args)

main()