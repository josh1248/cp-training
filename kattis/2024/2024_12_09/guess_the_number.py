import sys

low, high = 1, 1000
while True:
    guess = (low + high) // 2
    print(guess)
    sys.stdout.flush()
    if (res := sys.stdin.readline().strip()) == "lower":
        high = guess - 1
    elif res == "higher":
        low = guess + 1
    else:
        break
        