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

    int n; cin >> n;
    vector<ll> v(n); rep(i, 0, n) cin >> v[i];
    sort(all(v));
    ll res = 0;
    res += (n - 1) * v[0];
    rep(i, 1, n) res += v[i];
    cout << res << "\n";
}