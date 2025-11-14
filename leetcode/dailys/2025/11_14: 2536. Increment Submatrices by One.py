from collections import defaultdict
class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        # when to add and remove certain query IDs by row
        adds, removes = defaultdict(list), defaultdict(list)
        # query -> (start col, end col)
        query = {}
        for i in range(len(queries)):
            rstart, colstart, rend, colend = queries[i]
            query[i] = (colstart, colend)
            adds[rstart].append(i)
            removes[rend + 1].append(i)
        
        difference_array = [0] * (n + 1)
        ans = [[0] * n for _ in range(n)]
        for row in range(n):
            for to_add in adds[row]:
                colstart, colend = query[to_add]
                difference_array[colstart] += 1
                difference_array[colend + 1] -= 1
            for to_remove in removes[row]:
                colstart, colend = query[to_remove]
                difference_array[colstart] -= 1
                difference_array[colend + 1] += 1
            
            curr = 0
            for col in range(n):
                curr += difference_array[col]
                ans[row][col] = curr
        return ans
