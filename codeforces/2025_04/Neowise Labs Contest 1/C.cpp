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

vector<vector<ll>> memo;
vector<ll> costsr, costsc;
vector<vector<ll>> grid;
ll R;

const ll inf = 2e18;

ll dp_r(ll idx, bool prev_used) {
    if (idx >= R) return 0;
    ll& ans = memo[idx][prev_used ? 1 : 0];
    if (ans != - 1) return ans;
    
    if (idx == 0) {
        return ans = min({inf, dp_r(idx + 1, false), costsr[0] + dp_r(idx + 1, true)});
    } else {
        bool mustbuild = false, cannotbuild = false;
        rep(i, 0, R) {
            ll currbuilding = grid[idx][i],
                prevbuilding = grid[idx - 1][i] + (prev_used ? 1 : 0);
            if (currbuilding == prevbuilding) mustbuild = true;
            else if (currbuilding + 1 == prevbuilding) cannotbuild = true;
        }

        if (mustbuild && cannotbuild) return ans = inf;
        else if (mustbuild) return ans = min(inf, costsr[idx] + dp_r(idx + 1, true));
        else if (cannotbuild) return ans = min(inf, dp_r(idx + 1, false));
        else {
            return ans = min({inf, costsr[idx] + dp_r(idx + 1, true), dp_r(idx + 1, false)});
        }
    }
}

ll dp_c(ll idx, bool prev_used) {
    if (idx >= R) return 0;
    ll& ans = memo[idx][prev_used ? 1 : 0];
    if (ans != - 1) return ans;
    
    if (idx == 0) {
        return ans = min({inf, dp_c(idx + 1, false), costsc[0] + dp_c(idx + 1, true)});
    } else {
        bool mustbuild = false, cannotbuild = false;
        rep(i, 0, R) {
            ll currbuilding = grid[i][idx],
                prevbuilding = grid[i][idx - 1] + (prev_used ? 1 : 0);
            if (currbuilding == prevbuilding) mustbuild = true;
            else if (currbuilding + 1 == prevbuilding) cannotbuild = true;
        }

        if (mustbuild && cannotbuild) return ans = inf;
        else if (mustbuild) return ans = min(inf, costsc[idx] + dp_c(idx + 1, true));
        else if (cannotbuild) return ans = min(inf, dp_c(idx + 1, false));
        else {
            return ans = min({inf, costsc[idx] + dp_c(idx + 1, true), dp_c(idx + 1, false)});
        }
    }
}

void solve() {
    cin >> R;
    grid = vector<vector<ll>>(R, vector<ll>(R));
    costsr = vector<ll>(R), costsc = vector<ll>(R);
    rep(i, 0, R) {
        rep(j, 0, R) {
            cin >> grid[i][j];
        }
    }
    rep(i, 0, R) cin >> costsr[i];
    rep(i, 0, R) cin >> costsc[i];
    memo = vector<vector<ll>>(R, vector<ll>(2, -1));
    ll r_ans = dp_r(0, false);
    memo.clear();
    memo = vector<vector<ll>>(R, vector<ll>(2, -1));
    ll c_ans = dp_c(0, false);
    if (r_ans == inf || c_ans == inf) cout << -1 << "\n";
    else cout << r_ans + c_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}