#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

// best result for 1 person starting BEFORE gate i
vector<ll> dp_top, dp_btm;
vector<tuple<char, ll>> topgates, bottomgates;

// dp solve, ignoring all pluses, assuming starting BEFORE gate i
ll dp_solve(int i, bool top_gate_used) {
    if (i >= sz(topgates)) {
        return 1;
    } else if (top_gate_used) {
        ll& ans = dp_top[i];
        if (ans != -1) return ans;
        auto& [c, val] = topgates[i];
        if (c == '+') {
            ans = dp_solve(i + 1, true);
        } else {
            ans = dp_solve(i + 1, true) + (val - 1) * max(dp_solve(i + 1, true), dp_solve(i + 1, false));
        }
        return ans;
    } else {
        ll& ans = dp_btm[i];
        if (ans != -1) return ans;
        auto& [c, val] = bottomgates[i];
        if (c == '+') {
            ans = dp_solve(i + 1, false);
        } else {
            ans = dp_solve(i + 1, false) + (val - 1) * max(dp_solve(i + 1, true), dp_solve(i + 1, false));
        }
        return ans;
    }
}

void solve() {
    int N; cin >> N;
    dp_top.assign(N, -1), dp_btm.assign(N, -1);
    bottomgates.clear(), topgates.clear();
    rep(i, 0, N) {
        int g1, g2; char c1, c2;
        cin >> c1 >> g1 >> c2 >> g2;
        topgates.emplace_back(c1, g1);
        bottomgates.emplace_back(c2, g2);
    }

    ll res = dp_solve(0, true) + dp_solve(0, false);
    rep(i, 0, N) {
        {
            auto& [c, val] = topgates[i];
            if (c == '+') {
                res += val * max(dp_solve(i + 1, true), dp_solve(i + 1, false));
            }
        }
        {
            auto& [c, val] = bottomgates[i];
            if (c == '+') {
                res += val * max(dp_solve(i + 1, true), dp_solve(i + 1, false));
            }
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}