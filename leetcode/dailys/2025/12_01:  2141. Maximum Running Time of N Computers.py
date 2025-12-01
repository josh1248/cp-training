def canRun(n, guess, batteries):
    return sum(min(battery, guess) for battery in batteries) >= n * guess
        

class Solution:
    def maxRunTime(self, n, batteries) -> int:
        lo, hi = 0, sum(batteries) // n
        while lo < hi:
            guess = (lo + hi + 1) // 2
            if canRun(n, guess, batteries):
                lo = guess
            else:
                hi = guess - 1
        
        return lo