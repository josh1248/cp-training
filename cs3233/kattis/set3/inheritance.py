import itertools
n = int(input())
order = []
for r in range(1, 19):
    for s in itertools.product('24', repeat=r):
        i = int(''.join(s))
        if n % i == 0: order.append(i)
print(*order, sep='\n')