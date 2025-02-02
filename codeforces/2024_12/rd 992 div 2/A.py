from collections import defaultdict
lines_per_test_case = 2

def algo(i):
    k = i[0][1]
    modulos = defaultdict(lambda: [])
    for idx in range(i[0][0]):
        r = i[1][idx] % k
        modulos[r].append(idx)

    for i in range(k):
        if len(modulos[i]) == 1:
            return f"Yes\n{modulos[i][0] + 1}"
        
    return f"No"

def main():
    total_inputs = int(input())
    for _ in range(total_inputs):
        args = []
        for _ in range(lines_per_test_case):
            args.append([int(i) for i in input().split(" ")])
        print(algo(args))

main()