from sys import stdin

def algo(ins):
    arr = [[99999] * len(ins[0]) for _ in range(len(ins))]

    for r in range(len(ins)):
        for c in range(len(ins[0])):
            if ins[r][c] != "T":
                arr[r][c] = 0

    def depth_at(r, c):
        if r < 0 or r >= len(ins) or c < 0 or c >= len(ins[0]):
            return 0
        else:
            return arr[r][c]

    depth = 0
    flag = True
    while flag:
        flag = False
        for r in range(len(ins)):
            for c in range(len(ins[0])):
                if ins[r][c] == "T":
                    top = depth_at(r - 1, c) >= depth
                    btm = depth_at(r + 1, c) >= depth
                    lft = depth_at(r, c - 1) >= depth
                    rgt = depth_at(r, c + 1) >= depth
                    if top and btm and lft and rgt:
                        flag = True
                        arr[r][c] = depth + 1
        depth += 1
    
    if depth >= 11:
        for r in arr:
            print(''.join("..." if c == 0 else ".." + str(c) if c < 10 else "." + str(c) for c in r))
    else:
        for r in arr:
            print(''.join('.' + str(c) if c != 0 else '..' for c in r))


def main():
    args = []
    r = int(stdin.readline().strip().split(" ")[0])
    for _ in range(r):
        args.append([i for i in stdin.readline().strip()])
    algo(args)

main()