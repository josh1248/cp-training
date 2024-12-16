from sys import stdin
read = lambda: stdin.readline().strip()

def algo(arr):
    r = len(arr)
    o = []
    oset = set()
    leftset = set(i for i in range(1, r + 1))
    for n in arr:
        if n not in oset:
            o.append(n)
            oset.add(n)
            leftset.remove(n)
    return o + list(leftset)



def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        read()
        a = algo([int(i) for i in input().split(" ")])
        for i in a:
            print(i, end=" ")
        print()


main()