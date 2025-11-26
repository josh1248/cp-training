from math import lcm
n = int(input())
seq = input()

curr = 1
seq_idx = 0
flag = False
while True:
    curr_num = str(curr)
    for c in curr_num:
        if c == seq[seq_idx]:
            seq_idx += 1
        if seq_idx >= n:
            flag = True
            break
    
    if flag:
        break
    curr += 1

print(curr)