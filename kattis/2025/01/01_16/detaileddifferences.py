n = int(input())
for _ in range(n):
    x = input()
    y = input()
    print(x)
    print(y)
    print(''.join('.' if x[i] == y[i] else '*' for i in range(len(x))))
    print()