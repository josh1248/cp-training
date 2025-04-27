#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    unordered_map<string, int> mapping;
    rep(i, 0, n) {
        unordered_set<string> nodups;
        rep(j, 0, m) {
            string s; cin >> s;
            if (nodups.count(s) > 0) continue;
            if (mapping.count(s) == 0) mapping[s] = 0;
            mapping[s]++;
            nodups.insert(s);
        }
    }

    vector<string> ans;
    for (auto [k, v]: mapping) {
        if (v == n) ans.push_back(k);
    }
    cout << sz(ans) << "\n";
    sort(all(ans));
    for (string s: ans) cout << s << "\n";
}