from sys import stdin
import math
read = lambda: stdin.readline().strip()

def divs(m, d):
    return m // d

def algo(a, b, c, d):
    divisor = c * d // math.gcd(c, d)
    print(divs(b, divisor) - divs(a - 1, divisor))


def main():
    args = []
    a, b, c, d = [int(i) for i in read().split()]
    algo(a, b, c, d)

main()