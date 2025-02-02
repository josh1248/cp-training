lines_per_test_case = 1

def perms(n) -> list[list[int]]:
    if n == 1:
        return [[1]]
    else:
        [arr.insert() for arr in perms(n - 1)]

def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in input().split(" ")])
        print(algo(args))

main()