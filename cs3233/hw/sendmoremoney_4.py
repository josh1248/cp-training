import itertools, re

ns = re.split(r'[+=]', input())
letters = ''.join(sorted(set(l for n in ns for l in n)))
nonzeroes = [letters.find(n[0]) for n in ns]
c = [letters.find(l[-1]) for l in ns]

ans, alloc = 0, ''
for choice in itertools.combinations('0123456789', len(letters)):
    for p in itertools.permutations(choice):
        p = ''.join(p)
        if any(p[i] == '0' for i in nonzeroes) or (int(p[c[0]]) + int(p[c[1]]) + int(p[c[2]]) - int(p[c[3]])) % 10:
            continue
        t = str.maketrans(letters, p)
        x = [int(n.translate(t)) for n in ns]
        if x[0] + x[1] + x[2] == x[3]:
            if ans == 0 or p < alloc:
                ans = x
                alloc = p
print(f'{ans[0]}+{ans[1]}+{ans[2]}={ans[3]}' if ans else 'impossible')