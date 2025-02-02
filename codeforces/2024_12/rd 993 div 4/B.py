from sys import stdin
read = lambda: stdin.readline().strip()

lines_per_test_case = 2

def algo(i):
    o = 0
    return 0

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        s = read()
        for c in s[::-1]:
            if c == "w":
                print(c, end="")
            elif c == "p":
                print("q", end="")
            else:
                print("p", end="")
        print()


main()