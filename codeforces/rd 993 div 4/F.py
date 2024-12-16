from sys import stdin
import math
read = lambda: stdin.readline().strip()

def main():
    n, m, q = [int(i) for i in read().split(" ")]
    a = [int(i) for i in read().split(" ")]
    b = [int(i) for i in read().split(" ")]
    basesum = sum(a) * sum(b)
    aset, bset = set(a), set(b)

    for _ in range(q):
        desired = int(read())


main()