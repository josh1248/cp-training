class Solution:
    def isOneBitCharacter(self, bits: list[int]) -> bool:
        i = 0
        while i < len(bits):
            if bits[i] == 1:
                i += 2
                if i == len(bits):
                    return False
            else:
                i += 1
        return True