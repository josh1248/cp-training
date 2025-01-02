from collections import defaultdict
from sys import stdin
from bisect import bisect_left, bisect_right
read = lambda: stdin.readline().strip()

def algo(args):
    gaps = set(i for i in range(1, 2 * len(args) + 1))
    notunique = set()
    for i, j in args:
        if i == j:
            if i not in gaps:
                notunique.add(i)
            else:
                gaps.remove(i)

    # insertion ordered
    g = list(gaps)
    for i, j in args:
        if i == j:
            if i in notunique:
                print("0", end="")
            else:
                print("1", end="")
        else:
            if bisect_right(g, j) == bisect_left(g, i):
                print("0", end="")
            else:
                print("1", end="")
    print()


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        arg_length = int(read())
        args = []
        for _ in range(arg_length):
            args.append([int(i) for i in read().split(" ")])
        algo(args)

main()