from sys import stdin
read = lambda: stdin.readline().strip()

lines_per_test_case = 1

def algo(n, k):
    perms = [i for i in range(n, 0, -1)]
    if k == 1:
        for n in perms:
            print(n, end=" ")
        print()
        return
    
    slot = k - 1
    res = [0] * n
    while slot < n:
        res[slot] = perms.pop()
        slot += k
    
    for i in range(n):
        if res[i] == 0:
            res[i] = perms.pop()
    
    for n in res:
        print(n, end=" ")
    print()


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        for _ in range(lines_per_test_case):
            n, k = [int(i) for i in read().split(" ")]
        algo(n, k)

main()