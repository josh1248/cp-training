#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

string s;
unordered_set<string> choices;
vi costs;
ll bestcost = 1e9;

void backtrack(int idx) {
    if (idx >= sz(s)) {
        ll cost = 0;
        for (auto& k: choices) {
            cost += costs[sz(k) - 1];
        }
        bestcost = min(bestcost, cost);
    } else {
        string curr = "";
        rep(i, idx, sz(s)) {
            curr.append(1, s[i]);
            bool alr_in = choices.count(curr) > 0;
            if (!alr_in) choices.insert(curr);
            backtrack(i + 1);
            if (!alr_in) choices.erase(curr);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    costs = vi(sz(s));
    rep(i, 0, sz(s)) cin >> costs[i];

    backtrack(0);
    cout << bestcost << "\n";
}