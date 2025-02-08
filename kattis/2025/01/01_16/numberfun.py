n = int(input())
for _ in range(n):
    a, b, c = map(int, input().split())
    if (a + b == c or a - b == c or a * b == c or a / b == c):
        print("Possible")
        continue
    
    b, a = a, b
    if (a + b == c or a - b == c or a * b == c or a / b == c):
        print("Possible")
        continue
    
    print("Impossible")