from sys import stdin
read = lambda: stdin.readline().strip()

def algo(s):
    a = s.find("0")
    if a == -1 or a == len(s) - 1:
        print(f'1 {len(s)} 1 1')
        return

    to_xor = int(s[a:], 2)
    substr_len = len(s) - a
    substr_to_check = int(s[:substr_len], 2)
    
    ms_one = 1 << len(s) - a - 1
    max_xor = -1
    max_compatibility = 1
    for i in range(a):
        # print(substr_to_check)
        xor_val = to_xor ^ substr_to_check
        if xor_val > max_xor:
            max_compatibility = i
            max_xor = xor_val
        
        if s[i] == '1':
            substr_to_check -= ms_one

        substr_to_check = substr_to_check << 1
        
        if s[substr_len + i] == '1':
            substr_to_check += 1
    
    print(f'1 {len(s)} {max_compatibility + 1} {max_compatibility + substr_len}')


        


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        s = read()
        algo(s)

main()