class Solution:
    def get_ops(self, digit: int, a: int):
        """Returns number of times to add a to digit until digit is lowest possible"""
        lo = digit
        ans = 0
        # always doable in at most 9 iterations since modulo wraps back on itself after 10
        for ops in range(1, 10):
            new_digit = (digit + ops * a) % 10
            if lo > new_digit:
                lo = new_digit
                ans = ops
        return ans

    
    def lowest(self, s: str, a: int, can_add_evens: bool):
        """get the lowest we can drop this particular arrangement,
            given that we can only add but not rotate.
        """
        # (lowest we can get s[1], ops we need to get lowest s[1])
        odd_ops = self.get_ops(int(s[1]), a)
        even_ops = self.get_ops(int(s[0]), a)
        
        ans = []
        if can_add_evens:     
            for i in range(len(s)):
                if i % 2 == 1:
                    digit = (int(s[i]) + a * odd_ops) % 10
                else:
                    digit = (int(s[i]) + a * even_ops) % 10
                ans.append(str(digit))
        else:
            for i in range(len(s)):
                if i % 2 == 1:
                    digit = (int(s[i]) + a * odd_ops) % 10
                else:
                    digit = int(s[i])
                ans.append(str(digit))
        return "".join(ans)

    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        total_offset = 0
        s_curr = s
        lo = self.lowest(s, a, b % 2)
        while True:
            # go through all rotations possible
            s_curr = s_curr[-b:] + s_curr[:-b]
            total_offset += b
            if total_offset % len(s) == 0:
                break
            lo = min(lo, self.lowest(s_curr, a, b % 2))
        
        return lo