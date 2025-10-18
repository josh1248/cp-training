#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int distincts = 0;
        int prev_highest_num = -2e9;
        // greedy - always reduce the element to be as small as possible
        for (int i: nums) {
            int smallest_possible = max(prev_highest_num + 1, i - k);
            if (smallest_possible <= i + k) {
                distincts++;
                prev_highest_num = smallest_possible;
            }
        }
        return distincts;
    }
};