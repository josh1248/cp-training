#include <string>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        // need to exclude this headache case since changing doesnt
        // improve on number of partitions
        if (k == 26) {
            return 1;
        }

        vector<bitset<26>>
            prefix_seen_chars(s.size()),
            suffix_seen_chars(s.size());
        vector<int>
            prefix_prev_partitions(s.size()),
            suffix_prev_partitions(s.size());
        
        for (int i = 0; i < s.size(); i++) {
            int char_idx = s[i] - 'a';
            prefix_seen_chars[i] = (i == 0 ? 0 : prefix_seen_chars[i - 1]);
            prefix_prev_partitions[i] = (i == 0 ? 0 : prefix_prev_partitions[i - 1]);
            if ((prefix_seen_chars[i] | bitset<26>(1 << char_idx)).count() > k) {
                prefix_prev_partitions[i]++;
                prefix_seen_chars[i] = (1 << char_idx);
            } else {
                prefix_seen_chars[i] |= (1 << char_idx);
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            int char_idx = s[i] - 'a';
            suffix_seen_chars[i] = (i == s.size() - 1 ? 0 : suffix_seen_chars[i + 1]);
            suffix_prev_partitions[i] = (i == s.size() - 1 ? 0 : suffix_prev_partitions[i + 1]);

            if ((suffix_seen_chars[i] | bitset<26>(1 << char_idx)).count() > k) {
                suffix_prev_partitions[i]++;
                suffix_seen_chars[i] = (1 << char_idx);
            } else {
                suffix_seen_chars[i] |= (1 << char_idx);
            }
        }

        int best = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr_partitions = 0;
            if (i > 0) curr_partitions += prefix_prev_partitions[i - 1];
            if (i < s.size() - 1) curr_partitions += suffix_prev_partitions[i + 1];
            
            bitset<26>
                l_set = (i == 0 ? bitset<26>(0) : prefix_seen_chars[i - 1]),
                r_set = (i == s.size() - 1 ? bitset<26>(0) : suffix_seen_chars[i + 1]);
            
            bitset<26> combined_bitset = l_set | r_set;
            if (combined_bitset.count() < k) {
                curr_partitions++;
            } else if (l_set.count() == k && r_set.count() == k && combined_bitset.count() < 26) {
                curr_partitions += 3;
            } else {
                // curr slice will contribute to 2 partitions normally
                curr_partitions += 2;
            }
            best = max(best, curr_partitions);
        }
        
        return best;
    }
};