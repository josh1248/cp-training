lines_per_test_case = 3

def algo(ins):
    o = 0
    alt = -99999
    for i in range(ins[0][0]):
        u, b = ins[1][i], ins[2][i]
        large, small = max(u, b), min(u, b)

        o += large
        alt = max(alt, small)

    return o + alt
    

    
def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in input().split(" ")])
        print(algo(args))

main()