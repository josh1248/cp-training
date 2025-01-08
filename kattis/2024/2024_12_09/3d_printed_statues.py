from sys import stdin
lines_per_test_case = 1

def algo(ins):
    # input f(s, p):
    # if s <= 2p, can print in 2 days, no need to print printers
    # if s > 2p, then it is always better to print all printers.

    # day 1: print printer, day 2: 2 printers prints 2 statues
    # same as day 1 and 2: print statue
    days = 0
    s, p = ins[0][0], 1
    while s > 2 * p:
        days += 1
        p *= 2
    
    if s <= p:
        print(days + 1)
    else:
        print(days + 2)

def main():
    args = []
    for _ in range(lines_per_test_case):
        args.append([int(i) for i in stdin.readline().strip().split(" ")])
    algo(args)

main()