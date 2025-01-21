import itertools,re
ns=re.split(r'[+=]',input())
l=''.join(sorted(set(c for n in ns for c in n)))
nz=[l.find(n[0]) for n in ns]
c=[l.find(n[-1]) for n in ns]
R,alloc=0,''
for a in itertools.combinations('0123456789',len(l)):
    for p in itertools.permutations(a):
        p=''.join(p)
        if any(p[i]=='0' for i in nz) or (int(p[c[0]])+int(p[c[1]])-int(p[c[2]]))%10:
            continue
        t=str.maketrans(l, p)
        x=[int(n.translate(t))for n in ns]
        if x[0]+x[1]==x[2]and(R==0 or p<alloc):
            R,alloc=x,p
print(f'{R[0]}+{R[1]}={R[2]}'if alloc else'impossible')