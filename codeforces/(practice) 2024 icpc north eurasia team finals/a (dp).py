#!/usr/bin/env python3
n=int(input())
c=list(map(int,input().split()))
m=0
x=[]
y=[]

def algo(cars: list[int], startcar):
    global m
    if len(cars) <= 1:
        return 0
    else:
        i = cars.index(startcar)
        # get overtaken all the way to the back
        curr = 0
        while curr < len(cars):
            if curr == i:
                curr += 1
                continue 

            x.append(cars[curr])
            y.append(startcar)
            curr += 1
            m += 1
        
        curr -= 1

        # swap all the way to the current position by overtaking
        while curr > i:
            if curr == i:
                curr -= 1
                continue
            x.append(startcar)
            y.append(cars[curr])
            curr -= 1
            m += 1
        
        del cars[i]
        
        algo(cars, startcar + 1)

algo(c, 1)
print(m)
for i in range(m):
    print(x[-i-1],y[-i-1])
