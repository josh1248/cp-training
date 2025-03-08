from sys import stdin
from random import seed
read = lambda: stdin.readline().strip()


def main():
    args = []
    n = int(read())
    for i in range(n):
        m, r = [int(i) for i in read().split()]
        queries = [int(i) for i in read().split()]
        algo(m, r, queries)

main()