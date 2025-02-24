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

#define MOD 998244353
#define CAP 200'000
// vector<ll> precalc_powers(CAP + 1);

// void populate() {
//     ll result_now = 1;
//     for (int i = 1; i <= CAP; i++) {
//         result_now = (result_now << 1) % MOD;
//         precalc_powers[i] = result_now;
//     }
// }

void solve() {
    int n; cin >> n;
    
    vi data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vi prefix_ones(n, 0), prefix_threes(n, 0);
    int curr_ones = 0, curr_threes = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 1) {
            curr_ones++;
        } else if (data[i] == 3) {
            curr_threes++;
        }
        prefix_ones[i] = curr_ones;
        prefix_threes[i] = curr_threes;
    }

    auto rsq1 = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= n) return 0ll;
        else if (i == 0) return ll(prefix_ones[j]);
        else return ll(prefix_ones[j] - prefix_ones[i - 1]);
    };
    auto rsq3 = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= n) return 0ll;
        if (i == 0) return ll(prefix_threes[j]);
        else return ll(prefix_threes[j] - prefix_threes[i - 1]);
    };

    // consider subsequences involving that particular 2 as a middle element
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 2) {
            res += (rsq1(0, i - 1) * rsq3(i + 1, n - 1));
            res %= MOD;
        }
        cout << i << " " << res << "\n";
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // populate();
    int t; cin >> t; while (t--) solve();
}