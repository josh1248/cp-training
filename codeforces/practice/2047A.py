lines_per_test_case = 2

def algo(inputs):
    out = 1
    accum = 0
    for i in inputs[1:-1]:
        accum += i
        if accum ** 0.5 % 1 == 0 and accum % 2 == 1:
            out += 1
    return out

def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.extend([int(i) for i in input().split(" ")])
        print(algo(args))

main()