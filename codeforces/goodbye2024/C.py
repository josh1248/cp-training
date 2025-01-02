from sys import stdin
read = lambda: stdin.readline().strip()

def algo(n, k):
    if n < k:
        return (0, 0)
    elif n % 2 == 1:
        half = n >> 1
        wishsum, wishlen = algo(half, k)
        return ((half + 1) * (1 + wishlen) + 2 * wishsum, 2 * wishlen + 1)
    else:
        half = n >> 1
        wishsum, wishlen = algo(half, k)
        return (2 * wishsum + half * wishlen, 2 * wishlen)


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        n, k = [int(i) for i in read().split(" ")]
        ans, _ = algo(n, k)
        print(ans)

main()