from sys import stdin

def algo(ins):
    ins.sort(reverse=True)
    maxs = -1
    for i in range(len(ins)):
        maxs = max(maxs, ins[i] + i + 2)
    return maxs

def main():
    total_inputs = int(stdin.readline())
    print(algo([int(i) for i in stdin.readline().strip().split(" ")]))

main()