n = int(input())
b = 2
for _ in range(n):
    b = b << 1
    b -= 1
print(b ** 2)