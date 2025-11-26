n = int(input())
for _ in range(n):
    full = input()
    acronym = input()
    flag = False
    for letter in acronym:
        if letter not in full:
            flag = True
    print("NO" if flag else "YES")