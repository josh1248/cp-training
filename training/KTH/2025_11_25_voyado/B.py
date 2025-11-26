from math import lcm
i, a, b = [int(x) for x in input().split()]
fizzbuzz = i // lcm(a, b)
fizz = i // a - fizzbuzz
buzz = i // b - fizzbuzz
print(fizz, buzz, fizzbuzz)