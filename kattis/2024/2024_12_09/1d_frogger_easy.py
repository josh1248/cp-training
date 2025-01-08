from sys import stdin
lines_per_test_case = 2

def algo(ins):
    size, start, target = ins[0]
    board = ins[1]

    turns = 0
    curr = start
    seen = set()
    while True:
        if board[curr - 1] == target:
            print("magic")
            break
        elif curr in seen:
            print("cycle")
            break

        seen.add(curr)
        
        curr = curr + board[curr - 1]
        turns += 1
        if curr < 1:
            print("left")
            break
        elif curr > size:
            print("right")
            break
    
    print(turns)

    return 0

def main():
    args = []
    for _ in range(lines_per_test_case):
        args.append([int(i) for i in stdin.readline().strip().split(" ")])
    algo(args)

main()