from sys import stdin
read = lambda: stdin.readline().strip()

def permutations(l):
    if len(l) == 1:
        return [[], [l[0]]]
    else:
        not_using = permutations(l[1:])
        res = []
        for arr in not_using:
            for i in range(len(l) - 1):
                alt = list(arr)
                alt.insert(i, l[0])
                res.append(alt)

            alt = list(arr)
            alt.append(l[0])
            res.append(alt)
        res.extend(not_using)
        return res

def algo(s):
    res = 0
    for k in set(map(lambda t: int('0' + ''.join(t)), permutations(s))):
        # print(k)
        if (k > 1 and (k == 2 or all(k % i != 0 for i in range(2, int(k ** 0.5) + 1)))):
           res += 1
    print(res)

def main():
    args = []
    n = int(read())
    for i in range(n):
        algo(input())
main()