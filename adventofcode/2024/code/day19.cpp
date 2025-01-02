#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

class Trie {
private:
    Trie* nxts[5];
public:
    bool terminal;
    Trie() {
        terminal = false;
        for (int i = 0; i < 5; ++i) {
            nxts[i] = NULL;
        }
    }

    int idx(char c) {
        switch (c) {
        case 'w': return 0;
        case 'u': return 1;
        case 'b': return 2;
        case 'r': return 3;
        case 'g': return 4;
        default: return -1;
        }
    }

    void insert(string s) {
        Trie* curr = this;
        for (int i = 0; i < s.size(); ++i) {
            int next_idx = idx(s[i]);
            if (next_idx == -1) {
                break;
            }

            if (curr->nxts[next_idx] == NULL) {
                curr->nxts[next_idx] = new Trie();
            }

            curr = curr->nxts[next_idx];
        }
        curr->terminal = true;
    }

    Trie* recurse(char c) {
        return nxts[idx(c)];
    }
};

int main() {
    ifstream ins("../data/day19.txt");
    if (!ins) {
        return 1;
    }

    Trie towels;

    string s, t; 
    getline(ins, s);
    stringstream ss(s);
    while (ss >> t) {
        towels.insert(t);
    }

    getline(ins, s);

    vector<ll> dp; int res1 = 0; ll res2 = 0;
    while (getline(ins, s)) {
        dp.clear();
        ss = stringstream(s);
        ss >> t;
        const int bounds = t.size();
        
        dp = vector<ll>(bounds, 0);

        // bottom-up DP here: O(len(input) * len(longest towel))
        for (int i = 0; i < bounds; ++i) {
            int r = i;
            Trie* curr = &towels;
            while (r < bounds) {
                curr = curr->recurse(s[r]);

                if (curr == NULL) {
                    break;
                }

                if (curr->terminal) {
                    dp[r] += (i == 0 ? 1 : dp[i - 1]);
                }
                ++r;
            }
        }

        if (dp[bounds - 1] > 0) {
            ++res1;
        }
        res2 += dp[bounds - 1];
    }

    cout << "part 1: " << res1 << "\n";
    cout << "part 2: " << res2 << "\n";
    ins.close();
}