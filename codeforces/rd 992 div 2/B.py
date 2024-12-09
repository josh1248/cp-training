import math
lines_per_test_case = 1
def algo(i):
    o = 1
    target = i[0][0]
    if target == 1:
        return 1
    elif target <= 0:
        return 0
    
    curr = 1
    while curr < target:
        curr = (curr + 1) * 2
        o += 1
    return o

def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in input().split(" ")])
        print(algo(args))

main()