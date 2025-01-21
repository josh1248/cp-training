import itertools,re
s=re.split(r'[+=]',input())
l=''.join(sorted(set(c for n in s for c in n)))
z,c,R,b=[l.find(n[0])for n in s],[l.find(n[-1])for n in s],0,''
for a in itertools.combinations('0123456789',len(l)):
    for p in itertools.permutations(a):
        p=''.join(p)
        if any(p[i]=='0' for i in z)or(int(p[c[0]])+int(p[c[1]])-int(p[c[2]]))%10:
            continue
        x=[int(n.translate(str.maketrans(l, p)))for n in s]
        if x[0]+x[1]==x[2]and(R==0 or p<b):
            R,b=x,p
print(f'{R[0]}+{R[1]}={R[2]}'if b else'impossible')