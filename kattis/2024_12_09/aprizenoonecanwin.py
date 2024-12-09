from sys import stdin

def algo(arr, target):
    arr.sort()

    # binary search if TLE
    for i in range(1, len(arr)):
        if arr[i] + arr[i - 1] > target:
            print(i)
            return
    
    print(len(arr))


def main():
    _, target = [int(i) for i in stdin.readline().strip().split(" ")]
    algo([int(i) for i in stdin.readline().strip().split(" ")], target)

main()