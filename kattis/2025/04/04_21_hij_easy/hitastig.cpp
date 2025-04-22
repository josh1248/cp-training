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

    ll lo = 2e18, hi = -2e18;
    int n; cin >> n;
    ll x;
    rep(i, 0, n) {
        cin >> x;
        lo = min(lo, x);
        hi = max(hi, x);
    }
    cout << hi << " " << lo << "\n";
}