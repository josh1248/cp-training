#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

class WeightedTrie {
public:
    vector<WeightedTrie*> children;
    int weight;
    WeightedTrie(): children(27, nullptr), weight(0) {};

    void insert(string& s, int idx) {
        weight++;
        if (idx >= sz(s)) return;
        if (children[s[idx] - 'a'] == nullptr) {
            children[s[idx] - 'a'] = new WeightedTrie();
        }
        children[s[idx] - 'a']->insert(s, idx + 1);
    }

    ll findweight(string& s, int idx) {
        if (idx == sz(s)) return weight;
        else if (children[s[idx] - 'a'] == nullptr) return 0;
        else return children[s[idx] - 'a']->findweight(s, idx + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    WeightedTrie wt;
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        wt.insert(s, 0);
        cout << wt.findweight(s, 0) - 1 << "\n";
    }
}