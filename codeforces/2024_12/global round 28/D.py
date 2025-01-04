from sys import stdin
from bisect import bisect_right
read = lambda: stdin.readline().strip()

def algo(participants: list[int], problems: list[int]):
    problems_len = len(problems)
    kevin = participants[0]

    # can ignore all lower or equal rated peers
    pstack = sorted(filter(lambda x: x > kevin, participants), key=lambda x: -x)
    problems.sort()

    ranks = []

    # get all problems which will give rank 1
    i = bisect_right(problems, kevin)
    ranks = [1] * i
    
    tmp = []
    
    while True:
        if i >= len(problems):
            break
            
        while pstack and pstack[-1] < problems[i]:
            pstack.pop()
        
        tmp.append(len(pstack) + 1)
        i += 1
    
    ranks.extend(tmp[::-1])
    

    for k in range(1, problems_len + 1):
        # problems k - 1, 2k - 1, ... determine the rank
        # rank(problems) = max(rank per individual problem)
        print(sum(ranks[k-1::k]), end=" ")
    print()
        

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        read()
        participants = [int(i) for i in read().split(" ")]
        problems = [int(i) for i in read().split(" ")]
        algo(participants, problems)

main()