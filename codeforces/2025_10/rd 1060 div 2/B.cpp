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

void solve() {
    int n; cin >> n;
    vi v(n);
    ll ans = 0;
    rep(i, 0, n) cin >> v[i];
    int prefix_max = INT_MIN;
    rep(i, 0, n) {
        prefix_max = max(prefix_max, v[i]);
        // make indices 1, 3, ... as big as possible first
        if (i % 2 == 1) {
            v[i] = prefix_max;
        }
    }
    for (int i = 0; i < n; i += 2) {
        int l = (i == 0 ? INT_MAX : v[i - 1]),
            r = (i == n - 1 ? INT_MAX : v[i + 1]),
            diff_l = v[i] - l,
            diff_r = v[i] - r;
        ans += max(0, max(diff_l, diff_r) + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}