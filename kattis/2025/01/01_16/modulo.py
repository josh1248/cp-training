modulo = [0] * 42
for _ in range(10):
    modulo[int(input()) % 42] = 1
print(sum(modulo))