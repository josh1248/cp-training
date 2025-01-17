#include <iostream>
#include <algorithm>
#include <cstdio>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

class Trie {
public:
    int weight;
    vector<Trie*> nxts;
    
    Trie(): weight(0), nxts(26, nullptr) { }

    void insert(string &s, int i) {
        weight++;
        if (i < s.size()) {
            Trie* n_ptr = nxts[s[i] - 'a'];
            if (n_ptr == nullptr) {
                n_ptr = new Trie();
                nxts[s[i] - 'a'] = n_ptr;
            }
            n_ptr->insert(s, i + 1);
        }
    }
    
    int query(string &s, int i) {
        if (i == s.size()) {
            return weight;
        } else {
            Trie* n_ptr = nxts[s[i] - 'a'];
            if (n_ptr == nullptr) {
                return 0;
            } else {
                return n_ptr->query(s, i + 1);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    Trie res;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        res.insert(s, 0);
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        cout << res.query(s, 0) << "\n";
    }
}