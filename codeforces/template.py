from sys import stdin
read = lambda: stdin.readline().strip()

lines_per_test_case = 2

def algo(i):
    o = 0
    return 0

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in read().split(" ")])
        print(algo(args))

main()