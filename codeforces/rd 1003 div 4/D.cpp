#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> data;
    for (int i = 0; i < n; i++) {
        ll s = 0, curr = 0;
        for (int j = 0; j < m; j++) {
            ll x; cin >> x;
            curr += x;
            s += curr;
        }
        data.emplace_back(curr, s);
    }
    sort(all(data));
    ll res = 0;
    for (ll i = n - 1; i >= 0; i--) {
        auto& [curr, s] = data[i];
        res += s;
        res += curr * i * m;
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while(t--) solve();
}