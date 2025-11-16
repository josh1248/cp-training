class Solution:
    def numSub(self, s: str) -> int:
        zeroes = []
        zeroes.append(-1)
        for i in range(len(s)):
            if s[i] == "0":
                zeroes.append(i)
        zeroes.append(len(s))
        
        ans = 0
        MOD = 10 ** 9 + 7
        for i in range(len(zeroes) - 1):
            ones = zeroes[i + 1] - zeroes[i] - 1
            ans += ones * (ones + 1) // 2
            ans %= MOD
        return ans
        