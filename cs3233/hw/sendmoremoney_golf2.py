import itertools as t,re
s=re.split(r'[+=]',input())
l=''.join(sorted(set(c for n in s for c in n)))
z,c,R,b=[l.find(n[0])for n in s],[l.find(n[-1])for n in s],0,''
for a in t.combinations('0123456789',len(l)):
    for p in t.permutations(a):
        if all((p:=''.join(p))[i]!='0' for i in z)and((i:=int)(p[c[0]])+i(p[c[1]])-i(p[c[2]]))%10+1 and(R==0 or p<b)and(x:=[i(n.translate(str.maketrans(l, p)))for n in s])[0]+x[1]==x[2]:R,b=x,p
print(f'{R[0]}+{R[1]}={R[2]}'if b else'impossible')