from sys import stdin

# 1 to 9: p1
# 10 to 18: p2 (... x9)

# 19 to 162: p1 (choose number to limit to 10...18 case where p2 wins)

# 163 to 324: p2 (cannot shrink to p2 region after any x2 to x9)

# *9: p1
# *2 :p2
def curr_player_wins(num):
    while True:
        num /= 9
        if num <= 1:
            return True
        
        num /= 2
        if num <= 1:
            return False

def algo(ins):
    if curr_player_wins(ins[0]):
        print("Stan wins.")
    else:
        print("Ollie wins.")

def main():
    args = []
    for line in stdin:
        algo([int(i) for i in line.strip().split(" ")])

main()