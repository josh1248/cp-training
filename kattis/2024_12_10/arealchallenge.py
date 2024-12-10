# https://open.kattis.com/problems/areal
# Time: 00:02

from sys import stdin
read = lambda: stdin.readline().strip()

def algo(ins):
    print(4 * (ins ** 0.5))

def main():
    args = []
    a = [int(i) for i in read().split()][0]
    algo(a)

main()