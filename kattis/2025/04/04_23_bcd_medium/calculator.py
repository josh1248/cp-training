from sys import stdin
read = lambda: stdin.readline().strip()

while (s := read()):
    print(f"{eval(s):.2f}")