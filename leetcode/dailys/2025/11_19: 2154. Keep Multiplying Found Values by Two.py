from collections import Counter
class Solution:
    def findFinalValue(self, nums: list[int], original: int) -> int:
        cnts = set(nums)
        while original in cnts:
            original *= 2
        return original
        