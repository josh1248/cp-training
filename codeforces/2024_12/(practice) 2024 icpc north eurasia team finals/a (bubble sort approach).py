#!/usr/bin/env python3
n=int(input())
c=list(map(int,input().split()))
m=0
x=[]
y=[]
#swapped=set()
for i in range(n):
    for j in range(0,n-1-i):
        if c[j]>c[j+1]:
            m+=1
            x.append(c[j])
            y.append(c[j+1])
            print(c,c[j],c[j+1])
            c[j],c[j+1]=c[j+1],c[j]
        #elif (c[j],c[j+1]) not in swapped:
        else:
            m+=2
            x.append(c[j])
            x.append(c[j+1])
            y.append(c[j+1])
            y.append(c[j])
            print(c,c[j],c[j+1])
            #swapped.add((c[j],c[j+1]))
print(c)
print(m)
for i in range(m-1,-1,-1):
    print(x[i],y[i])
