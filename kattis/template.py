from sys import stdin
read = lambda: stdin.readline().strip()

def algo(ins):
    print()

def main():
    args = []
    a, b = read().split()
    args.append([int(i) for i in read().split()])
    algo(args)

main()