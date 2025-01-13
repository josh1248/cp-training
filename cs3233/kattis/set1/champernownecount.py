from sys import stdin
read = lambda: stdin.readline().strip()

def main():
    n, k = [int(i) for i in read().split()]
    
    
    # holds the remainder of 10^(digits to the right) % k
    # we can then compute ((new number) * ((10 ^ digits) % k)) % k
    base = 1
    remainder = 0
    res = 0
    for i in range(1, n + 1):
        digits_added = len(str(i))
        remainder *= (10 ** digits_added)
        remainder += i
        remainder %= k
        if remainder == 0:
            res += 1
    print(res)
        
main()