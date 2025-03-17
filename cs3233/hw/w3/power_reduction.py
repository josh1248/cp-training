def fibs(power):
    if power == 0: return (0, 0)
    if power == 1: return (1, 0) # coefficients of x term and constant term
    a, b = fibs(power // 2)
    asq, bsq, ab = a*a, b*b, a*b
    # (ax + b)^2
    # = a^2x^2 + 2abx + b^2
    # = (a^2 + 2ab)x + (b^2 + a^2)
    # odd power:
    # = (a^2 + 2ab)x^2 + (b^2 + a^2)x
    # = (2a^2 + 2ab + b^2)x + (a^2 + 2ab)
    if power % 2 == 0:
        return ((asq + (ab << 1)) % m, (asq + bsq) % m)
    else:
        return ((((asq + ab) << 1) + bsq) % m, (asq + (ab << 1)) % m)

def fibs_iter(power):
    if power == 0: return 0
    a, b = 0, 1
    for c in bin(power)[2:]:
        asq, bsq, ab = a*a, b*b, a*b
        if c == '1':
            a, b = (((asq + ab) << 1) + bsq) % m, (asq + (ab << 1)) % m
        else:
            a, b = (asq + (ab << 1)) % m, (asq + bsq) % m
    
    return a

m = 10**10
print ('fibs | fibs_iter')
for i in range(30):
    print(f'F_{i}: {fibs(i)[0]} | {fibs_iter(i)}')

print(fibs_iter(10**99999)) # integer limit - only iter can due to recursion depth