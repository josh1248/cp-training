from sys import stdin
read = lambda: stdin.readline().strip()

# cat in.txt | python3 sara.py > out.txt
def decrypt(line):
    # 0 state - "ub" not seen, or used up
    # 1 state - "u" seen
    # 2 state - "ub" seen - accept incoming vowel
    state = 0
    caps = False
    for i in range(len(line)):
        if state == 0:
            if line[i] in "uU":
                # must be a u in "ub" rather than a free "u"
                state = 1
                if line[i] == 'U':
                    caps = True
            else:
                print(line[i], end="")
        elif state == 1:
            state = 2
        else:
            state = 0
            print(line[i].upper() if caps else line[i], end="")
            caps = False
    print()

def encrypt(line):
    for i in range(len(line)):
        if line[i] in 'aeiouy':
            print('ub', end='')
            print(line[i], end='')
        elif line[i] in 'AEIOUY':
            print('Ub', end='')
            print(line[i].lower(), end='')
        else:
            print(line[i], end='')
    print()

def main():
    s = read()
    lines = int(read())
    if s == 'A':
        for _ in range(lines):
            decrypt(read())
    else:
        for _ in range(lines):
            encrypt(read())

main()