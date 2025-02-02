from sys import stdin
read = lambda: stdin.readline().strip()

def algo(i):
    o = 0
    return 0

total_inputs = int(read())
for _ in range(total_inputs):
    n = int(input())
    a = [int(i) for i in read().split()]
    b = [int(i) for i in read().split()]
    if len(set(a)) * len(set(b)) >= 3:
        print("YES")
    else:
        print("NO")

