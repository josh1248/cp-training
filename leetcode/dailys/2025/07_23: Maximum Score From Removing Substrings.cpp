#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> prios = x > y ? vector<char>({'a', 'b'}) : vector<char>({'b', 'a'});
        s += 'x';

        // greeding for higher value substring is always optimal.
        // proof:
        // this will not change the total number of removals we can make,
        // which will always be exactly min(count('a'), count('b'))
        // AND it cannot possibly cause less removals of higher value
        // removal. e.g. when removing "ba", it cant reduce other "ba" removals
        // since both letters cant be separately removed by them.
        int a_cnt = 0, b_cnt = 0;

        int ans = 0;
        vector<char> stack;
        for (int pos = 0; pos < s.size(); pos++) {
            if (s[pos] == 'a') a_cnt++;
            else if (s[pos] == 'b') b_cnt++;
            else {
                // now, only possible remaining pairs are the non-prioritized strings
                // they wont possibly cause more prio pairs.
                // suppose prio pair is ab and alt pair is ba. then since no more ab pairs,
                // only possibility is bbbbbbb...aaaaaaaa... or bbbb... or aaaa...
                ans += min(x, y) * min(a_cnt, b_cnt);
                a_cnt = b_cnt = 0;
            }

            stack.push_back(s[pos]);

            // amortized O(1) time - remove all prioritized strings
            while (stack.size() >= 2) {
                if (stack[stack.size() - 2] == prios[0] && stack[stack.size() - 1] == prios[1]) {
                    stack.pop_back(); stack.pop_back();
                    ans += max(x, y);
                    a_cnt--, b_cnt--;
                } else {
                    break;
                }
            }
        }
        
        
        return ans;
    }
};