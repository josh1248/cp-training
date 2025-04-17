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

    int n; cin >> n;
    unordered_map<string, int> cnts;
    rep(i, 0, n) {
        vector<string> x(5);
        rep(i, 0, 5) cin >> x[i];
        sort(all(x));
        string key = x[0] + x[1] + x[2] + x[3] + x[4];
        if (cnts.count(key) == 0) {
            cnts[key] = 0;
        }
        cnts[key]++;
    }
    int maxseen = 0;
    for (auto& [k, v]: cnts) {
        maxseen = max(maxseen, v);
    }
    int res = 0;
    for (auto& [k, v]: cnts) {
        if (v == maxseen) {
            res += v;
        }
    }
    cout << res << "\n";
}