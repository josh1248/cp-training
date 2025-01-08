from sys import stdin
lines_per_test_case = 1

def algo(ins):
    n = ins[0][0]
    if n < 100:
        print(99)
    elif n % 100 < 49:
        print((n - n % 100) - 1)
    else:
        print((n - n % 100) + 99)


def main():
    args = []
    for _ in range(lines_per_test_case):
        args.append([int(i) for i in stdin.readline().strip().split(" ")])
    algo(args)

main()