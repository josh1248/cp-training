a = input()
b = input()

still_equal = True

if len(a) < len(b):
    print(len(b))
else:
    ans = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            still_equal = False
        
        if not (still_equal and a[i] == '0'):
            ans += 1
    print(ans)