from sys import stdin
read = lambda: stdin.readline().strip()

def algo(arr):
    # first one stores outgoing, second one stores incoming
    ins = [False] * len(arr)

    for i in range(len(arr)):
        ins[arr[i]] = True
    
    # mark cycles
    incycle = [False] * len(arr)
    def dfs(n):
        visited = set()
        curr = n
        while curr not in visited:
            if incycle[curr]:
                return
            visited.add(curr)
            curr = arr[curr]


        
        mark = curr
        incycle[curr] = True
        curr = arr[curr]
        while curr != mark:
            incycle[curr] = True
            curr = arr[curr]


    for i in range(len(arr)):
        if not ins[i]:
            dfs(i)

    maxcycle = 1
    for i in range(len(arr)):
        # traverse and find when an outbound plushie enters a cycle
        if not ins[i]:
            curr = i
            t = 1
            while not incycle[curr]:
                curr = arr[curr]
                t += 1
            maxcycle = max(maxcycle, t)
    
    return maxcycle + 1

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        read()
        print(algo([int(i) - 1 for i in read().split(" ")]))

    print(algo([i for i in range(1, 10001)] + [1] * 10000))
main()