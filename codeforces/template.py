from sys import stdin
read = lambda: stdin.readline().strip()

def algo(i):
    o = 0
    return 0

total_inputs = int(read())
for _ in range(total_inputs):
    args = [int(i) for i in read().split()]
    print(algo(args))

