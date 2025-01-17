from sys import stdin
read = lambda: stdin.readline().strip()

def main():
    n = int(read())
    for _ in range(n):
        l = int(input())
        print(sum(sorted(int(i) for i in input().split())[l::2]))
main()

