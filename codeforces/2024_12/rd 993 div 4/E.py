from sys import stdin
import math
read = lambda: stdin.readline().strip()


    

def algo(k, l1, r1, l2, r2):
    # consider just y = x * 1, with n = 0. if xrange > yrange, no more.
    if l2 > r1:
        res = 0
    elif l1 > r2:
        return 0
    elif l1 <= l2:
        if r1 >= r2:
            res = math.floor(r2) - math.ceil(l2) + 1
        else:
            res = math.floor(r1) - math.ceil(l2) + 1
    else:
        if r2 >= r1:
            res = math.floor(r1) - math.ceil(l1) + 1
        else:
            res = math.floor(r2) - math.ceil(l1) + 1
    

    return res + algo(k, l1, r1, l2 / k, r2 / k)
    
    



def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        k, l1, r1, l2, r2 = [int(i) for i in input().split(" ")]
        print(algo(k, l1, r1, l2, r2))


main()