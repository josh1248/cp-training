from sys import stdin
read = lambda: stdin.readline().strip()

n, k = map(int, input().split())
partitions = [0]
partitions.extend(list(map(int, input().split())))
partitions.append(n)
res = set()
for i in range(k + 2):
    for j in range(i + 1, k + 2):
        res.add(partitions[j] - partitions[i])

print(' '.join(str(s) for s in sorted(list(res))))