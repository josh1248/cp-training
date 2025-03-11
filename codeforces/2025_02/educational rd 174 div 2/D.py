from sys import stdin
read = lambda: stdin.readline().strip()

to_check = "placeholder string"
def algo(s):
    global to_check
    i = 0
    while i < len(s) // 2:
        if s[i] == s[-i-1]:
            i += 1
        else:
            to_check = s
            algo_proper()
            break


def algo_proper():
    first_char = to_check[0]
    last_char = to_check[-1]
    first_char_pos = [i for i in range(len(to_check)) if to_check[i] == first_char]
    last_char_pos = [i for i in range(len(to_check)) if to_check[i] == last_char]

    best_ans = len(to_check)
    low, high = 0, len(first_char_pos) - 1
    while low < high:
        mid = (low + high) // 2
        mid_pos = first_char_pos[mid]
        print('Check ', mid_pos, to_check[mid_pos::-1] + to_check[mid_pos+1:])
        if (to_check[mid_pos::-1] + to_check[mid_pos+1:] == to_check):
            high = mid
        else:
            low = mid + 1
    
    print(low, high)
            

total_inputs = int(read())
for _ in range(total_inputs):
    print(algo(read()))

