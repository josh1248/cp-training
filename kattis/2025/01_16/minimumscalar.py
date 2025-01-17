n = int(input())
for i in range(n):
    m = int(input())
    x = sorted(map(int, input().split()))
    y = sorted(map(int, input().split()))
    print(f'Case #{i + 1}: {sum(a * b for a, b in zip(x, y[::-1]))}')