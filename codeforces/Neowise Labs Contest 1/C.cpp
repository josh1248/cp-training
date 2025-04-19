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

vector<ll> memo;
vector<ll> costsr, costsc;
vector<vector<ll>> grid;
ll R;

const ll inf = 2e18;

ll map_fn(ll r, ll c, bool prev_r_used, bool prev_c_used) {
    return r + (R * c) 
        + (R * R * (prev_r_used ? 1 : 0))
        + (2ll * R * R * (prev_c_used ? 1 : 0));
}

ll dp(ll r, ll c, bool prev_r_used, bool prev_c_used) {
    // cout << r << " " << c;
    if (r >= R && c >= R) return 0;
    ll& ans = memo[map_fn(r, c, prev_r_used, prev_c_used)];
    if (ans != -1) return ans;
    ll rowused = inf, rownotused = inf, colused = inf, colnotused = inf;
    if (r == 0) {
        rowused = costsr[0] + dp(r + 1, c, true, prev_c_used);
        rownotused = dp(r + 1, c, false, prev_c_used);
    } else if (r < R) {
        bool mustrenovate = false, cannotrenovate = false;
        rep(i, 0, R) {
            ll currbuilding = grid[r][i], prevbuilding = grid[r - 1][i] + (prev_r_used ? 1 : 0);
            if (prevbuilding == currbuilding) {
                // must renovate, no choice
                mustrenovate = true;
            } else if (prevbuilding + 1 == currbuilding) {
                // cannot renovate, or else clash with previous row
                cannotrenovate = true;
            }
        }

        if (mustrenovate && cannotrenovate) {
            // we are at an impossible state
            return ans = inf;
        } else if (mustrenovate) {
            rowused = costsr[r] + dp(r + 1, c, true, prev_c_used);
        } else if (cannotrenovate) {
            rownotused = dp(r + 1, c, false, prev_c_used);
        } else {
            rowused = costsr[r] + dp(r + 1, c, true, prev_c_used);
            rownotused = dp(r + 1, c, false, prev_c_used);
        }
    }

    if (c == 0) {
        colused = costsc[0] + dp(r, c + 1, prev_r_used, true);
        colnotused = dp(r, c + 1, prev_r_used, false);
    } else if (c < R) {
        bool mustrenovate = false, cannotrenovate = false;
        rep(i, 0, R) {
            ll currbuilding = grid[i][c], prevbuilding = grid[i][c - 1] + (prev_c_used ? 1 : 0);
            if (prevbuilding == currbuilding) {
                // must renovate, no choice
                continue; mustrenovate = true;
            } else if (prevbuilding + 1 == currbuilding) {
                // cannot renovate, or else clash with previous row
                cannotrenovate = true;
            }
        }

        if (mustrenovate && cannotrenovate) {
            // we are at an impossible state
            return ans = inf;
        } else if (mustrenovate) {
            colused = costsc[c] + dp(r, c + 1, prev_r_used, true);
        } else if (cannotrenovate) {
            colnotused = dp(r, c + 1, prev_r_used, false);
        } else {
            colused = costsc[c] + dp(r, c + 1, prev_r_used, true);
            colnotused = dp(r, c + 1, prev_r_used, false);
        }
    }
    ans = min({rowused, rownotused, colused, colnotused});
    cout << r << " " << c << " " << ans << "\n";
    return ans;
}

void solve() {
    cin >> R;
    memo = vector<ll>(4 * R * R, -1ll);
    costsr = vector<ll>(R), costsc = vector<ll>(R);
    grid = vector<vector<ll>>(R, vector<ll>(R));
    rep(i, 0, R) {
        rep(j, 0, R) {
            cin >> grid[i][j];
        }
    }
    rep(i, 0, R) cin >> costsr[i];
    rep(i, 0, R) cin >> costsc[i];
    cout << dp(0, 0, false, false) << "\n";    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}