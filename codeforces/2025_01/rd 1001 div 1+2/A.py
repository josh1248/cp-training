from sys import stdin
read = lambda: stdin.readline().strip()


total_inputs = int(read())
for _ in range(total_inputs):
    print(read().count('1'))
