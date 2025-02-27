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

const int start = 449 * 448 / 2;

// // dp - store min uses, parent - store previous score
// vector<ll> dp(1e5 + 1), parent(1e5 + 1);

// void populate_dp() {
//     dp[0] = 
// }

void solve() {
    int k; cin >> k;
    vi decomposition;
    int decomp_sum = 0;
    int curr = start, n = 449;
    while (k > 0) {
        while (k >= curr) {
            k -= curr;
            decomposition.push_back(n);
            decomp_sum += n;
        }

        if (k == 0) break;
        curr = curr * (n - 2) / n;
        n--;
    }
    if (decomp_sum <= 500) {
        cout << decomp_sum << "\n";
        int unique = 0;
        rep(i, 0, sz(decomposition)) {
            int d = decomposition[i];
            rep(j, 0, d) {
                cout << i << " " << unique << "\n";
                unique++;
            }
        }
    } else {
        ll used_so_far = 0, cutoff = 0;
        rep(i, 0, sz(decomposition)) {
            int d = decomposition[i];
            if (d + used_so_far > 500) {
                cutoff = i;
                break;
            }
        }
        vector<pi> res(used_so_far);
        rep(i, 0, used_so_far) {
            res[i] = {i, i};
        }
        int iter = 0;
        rep(i, 0, cutoff) {
            int d = decomposition[i];
            rep(j, 0, d) {
                res[iter].first = i;
                iter++;
            }
        }
        iter = 0;
        rep(i, cutoff, sz(decomposition)) {
            int d = decomposition[i];
            rep(j, 0, d) {
                res[iter].second = i;
                iter++;
            }
        }
        cout << used_so_far << "\n";
        for (auto& [x, y]: res) {
            cout << x << " " << y << "\n";
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}