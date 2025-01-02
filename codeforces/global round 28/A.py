from sys import stdin
read = lambda: stdin.readline().strip()

lines_per_test_case = 1

def algo(i):
    if i % 33 == 0:
        print("Yes")
    else:
        print("No")

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in read().split(" ")])
        algo(args[0][0])

main()