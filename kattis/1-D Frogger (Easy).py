from sys import stdin
lines_per_test_case = 2

def algo(ins):
    o = 0
    return 0

def main():
    args = []
    for _ in range(lines_per_test_case):
        args.append([int(i) for i in stdin.readline().strip().split(" ")])
    algo(args)

main()