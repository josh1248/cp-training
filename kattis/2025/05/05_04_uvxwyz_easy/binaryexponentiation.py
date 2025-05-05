from sys import stdin
read = lambda: stdin.readline().strip()

def algo(a, e, m):
    if e == 0: return 1
    elif e == 1: return a % m
    elif e % 2 == 0:
        return algo((a * a) % m, e // 2, m) % m
    else:
        return (a * (algo((a * a) % m, e // 2, m) % m)) % m

def main():
    a, e, m = [int(i) for i in read().split()]
    print(algo(a, e, m))

main()