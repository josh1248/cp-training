class Solution:
    def maxOperations(self, s: str) -> int:
        s += "1"
        prevZeroes = 0
        ans = 0
        for i in range(len(s)):
            if s[i] == "1":
                if i > 0 and s[i - 1] == "0":
                    ans += prevZeroes
                prevZeroes += 1
        return ans

        