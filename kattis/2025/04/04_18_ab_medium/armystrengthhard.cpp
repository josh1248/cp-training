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
    while (t--) {
        int n, m; cin >> n >> m;
        ll maxn = -1, maxm = -1;
        rep(i, 0, n) {
            ll x; cin >> x;
            maxn = max(maxn, x);
        }
        rep(i, 0, m) {
            ll x; cin >> x;
            maxm = max(maxm, x);
        }
        cout << (maxn >= maxm ? "Godzilla" : "MechaGodzilla") << "\n";
    }
}