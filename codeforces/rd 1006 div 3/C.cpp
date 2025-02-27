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
    int n, x; cin >> n >> x;
    vi ans(n, 0);
    ans[0] = x;

    int m = 0;
    rep(i, 0, 31) {
        m = i;
        if (!(1 & (x >> i))) {
            break;
        }
    }
    int max_cap = (1 << m) - 1;

    int acc = 0;
    rep(i, 0, n) {
        if (i > max_cap) {
            break;
        }
        ans[i] = i;
        acc |= i;
    }

    if (acc < x) {
        ans[n - 1] = x;
    }

    for (int i: ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}