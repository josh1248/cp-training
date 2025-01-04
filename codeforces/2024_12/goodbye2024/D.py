from sys import stdin
from bisect import bisect_left
read = lambda: stdin.readline().strip()

def algo(a, b, q):
    a_sorted = [(a[i], i) for i in range(len(a))]
    b_sorted = [(b[i], i) for i in range(len(b))]
    a_sorted.sort()
    b_sorted.sort()
    mult = 1
    for i in range(len(a)):
        mult *= min(a_sorted[i], b_sorted[i])[0]
        mult %= 998244353
    print(mult, end=" ")

    a_map = {}
    b_map = {}
    for i in range(len(a)):
        a_map[a_sorted[i][1]] = i
        b_map[b_sorted[i][1]] = i
    
    for o, x in q:
        if o == 1:
            a[x - 1] += 1
            idx_now = a_map[x - 1]
            r = min(bisect_left(a_sorted, a[x - 1], key=lambda t: t[0]), len(a) - 1)

            tmp_val, tmp_idx = a_sorted[r]
            a_map[tmp_idx] = idx_now
            a_map[x - 1] = r
            a_sorted[idx_now] = (tmp_val, tmp_idx)
            a_sorted[r] = (a[x - 1], x - 1)

            if a_sorted[r] <= b_sorted[r]:
                mult *= a_sorted[r][0]
                mult //= (a_sorted[r][0] - 1)
                mult %= 998244353 
        else:
            b[x - 1] += 1
            idx_now = b_map[x - 1]
            r = min(bisect_left(b_sorted, b[x - 1], key=lambda t: t[0]), len(b) - 1)

            tmp_val, tmp_idx = b_sorted[r]
            b_map[tmp_idx] = idx_now
            b_map[x - 1] = r
            b_sorted[idx_now] = (tmp_val, tmp_idx)
            b_sorted[r] = (b[x - 1], x - 1)
            
            if a_sorted[r] >= b_sorted[r]:
                mult *= b_sorted[r][0]
                mult //= (b_sorted[r][0] - 1)
                mult %= 998244353 
                
        print(mult, end=" ")
    print()
    



def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        _, qlen = [int(i) for i in read().split(" ")]
        a = [int(i) for i in read().split(" ")]
        b = [int(i) for i in read().split(" ")]
        q = []
        for _ in range(qlen):
            q.append([int(i) for i in read().split(" ")])
        algo(a, b, q)

main()