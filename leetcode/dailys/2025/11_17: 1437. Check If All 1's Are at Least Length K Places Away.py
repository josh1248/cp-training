class Solution:
    def kLengthApart(self, nums: list[int], k: int) -> bool:
        dist = 0
        for i in nums:
            if i == 1:
                if dist > 0:
                    return False
                dist = k
            else:
                dist -= 1
        return True
        