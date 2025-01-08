from sys import stdin
read = lambda: stdin.readline().strip()

def algo(ins):
    if len(ins) >= 2 and ins[0] == "simon" and ins[1] == "says":
        print(" ".join(ins[2:]))
    else:
        print("")

def main():
    args = []
    a = [int(i) for i in read().split()][0]
    for _ in range(a):
        algo(read().split())

main()