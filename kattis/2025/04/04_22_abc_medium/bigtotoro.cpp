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

    // modulo changes:
    // 0 -> 0
    // 1 -> 2
    // 2 -> 0
    // 3 -> 2
    // starting: 0 -> 0 -> ...
    // or 1 -> 2 -> 0 -> ...
    // or 2 -> 0 -> ...
    // or 3 -> 2 -> 0 -> ...
    ll n, k; cin >> n >> k;
    vector<vector<ll>> acorn(4);
    rep(i, 0, n) {
        ll x; cin >> x;
        acorn[x % 4].push_back(x);
    }

    ll sum0 = 0;
    for (ll& i: acorn[0]) sum0 += i;
    ll max1 = -1, max2 = -1, max3 = -1;
    for (ll& i: acorn[1]) max1 = max(max1, i);
    for (ll& i: acorn[2]) max2 = max(max2, i);
    for (ll& i: acorn[3]) max3 = max(max3, i);
    if (k % 4 == 0) cout << k + sum0 << "\n";
    else if (k % 4 == 1) {
        if (sz(acorn[1]) == 0) cout << k << "\n";
        else if (sz(acorn[2]) == 0) cout << k + max1 << "\n";
        else cout << k + max1 + max2 + sum0 << "\n";
    } else if (k % 4 == 2) {
        if (sz(acorn[2]) == 0) cout << k << "\n";
        else cout << k + max2 + sum0 << "\n";
    } else if (k % 4 == 3) {
        if (sz(acorn[3]) == 0) cout << k << "\n";
        else if (sz(acorn[2]) == 0) cout << k + max3 << "\n";
        else cout << k + max3 + max2 + sum0 << "\n";
    }
}