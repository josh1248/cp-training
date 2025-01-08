# https://open.kattis.com/problems/shopaholic
from sys import stdin
read = lambda: stdin.readline().strip()

def algo(ins):
    ins.sort(reverse=True)
    disc = 0
    for i in range(len(ins) // 3):
        disc += ins[3 * i + 2]
    print(disc)


def main():
    args = []
    _ = [int(i) for i in read().split()]
    args.append([int(i) for i in read().split()])
    algo(args[0])

main()