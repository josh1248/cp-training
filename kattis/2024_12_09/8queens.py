# https://open.kattis.com/problems/8queens
from sys import stdin

def algo(ins):
    rows, cols, diags1, diags2 = set(), set(), set(), set()
    for r in range(len(ins)):
        c = ins[r].find('*')
        if c == -1:
            print('invalid')
            return
        else:
            if r in rows or c in cols or r + c in diags1 or r - c in diags2:
                print('invalid')
                return
            rows.add(r)
            cols.add(c)
            diags1.add(r + c)
            diags2.add(r - c)
    
    print('valid')

def main():
    args = []
    for _ in range(8):
        args.append(stdin.readline().strip())
    algo(args)

main()