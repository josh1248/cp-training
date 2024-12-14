from sys import stdin
read = lambda: stdin.readline().strip()

def sums(k):
    return k * (k + 1) // 2

def algo(i):
    n, k = i
    l, r = 0, n - 1
    mins = float('inf')
    base = sums(k - 1)
    while l <= r:
        mid = (l + r) // 2
        val = (sums(k + mid) - base) - (sums(k + n - 1) - sums(k + mid))
        mins = min(mins, abs(val))
        if val > 0:
            r = mid - 1
        elif val < 0:
            l = mid + 1
        else:
            return 0

    return int(mins)
    

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        for _ in range(1):
            print(algo([int(i) for i in read().split(" ")]))

main()