import heapq

lines_per_test_case = 2

def algo(i):
    o = 0
    in_order = []
    out_of_order = []
    for k in range(i[0] - 1):
        


    return 0

def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in input().split(" ")])
        print(algo(args))

main()