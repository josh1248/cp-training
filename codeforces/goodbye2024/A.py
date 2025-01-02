from sys import stdin
read = lambda: stdin.readline().strip()

def algo(nums):
    # just need to check existence of >1 size partition
    for i in range(len(nums) - 1):
        l, r = min(nums[i], nums[i + 1]), max(nums[i], nums[i + 1])
        if 2 * l > r:
            print("YES")
            return
    print("NO")


def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        read()
        args = [int(i) for i in read().split(" ")]
        algo(args)

main()