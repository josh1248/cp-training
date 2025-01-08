from sys import stdin

def algo(s, r, arr):
    se = set(arr)
    left = [i for i in range(1, s + 1) if i not in se]

    curr_r, curr_left = 0, 0
    out = []
    while curr_r < r and curr_left < len(left):
        if left[curr_left] < arr[curr_r]:
            out.append(left[curr_left])
            curr_left += 1
        else:
            out.append(arr[curr_r])
            curr_r += 1
    
    if curr_r == r:
        out.extend(left[curr_left:])
    elif curr_left == len(left):
        out.extend(arr[curr_r:])

    for i in out:
        print(str(i))


def main():
    args = []
    s, r = map(int, stdin.readline().strip().split())
    for _ in range(r):
        args.append(int(stdin.readline().strip()))
    algo(s, r, args)

main()