from sys import stdin
read = lambda: stdin.readline().strip()

total_inputs = int(read())
for _ in range(total_inputs):
    read()
    args = ''.join([i for i in read().split()])
    if '101' in args:
        print('NO')
    else:
        print('YES')

