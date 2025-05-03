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

    int t; cin >> t;
    unordered_map<string, ll> m;
    rep(i, 0, t) {
        string s; ll x; cin >> s >> x;
        if (m.count(s) == 0) m[s] = 0;
        m[s] += x;
    }
    ll best = -1; string ans = "";
    for (auto& [k, v]: m) {
        if (v > best) {
            best = v;
            ans = k;
        }
    }
    cout << ans << "\n";
}