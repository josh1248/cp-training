from sys import stdin
read = lambda: stdin.readline().strip()


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        m, a, b, c = [int(i) for i in input().split(" ")]
        r1 = min(a, m)
        r2 = min(b, m)
        rany = min(c, 2 * m - r1 - r2)
        print(r1 + r2 + rany)


main()