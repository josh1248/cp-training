from sys import stdin

for line in stdin:
    a, b = [int(i) for i in  line.strip().split(" ")]
    print(abs(a - b))