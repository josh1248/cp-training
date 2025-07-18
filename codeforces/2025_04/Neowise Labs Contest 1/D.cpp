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

ll dx[3] = {0, 1, 1};
ll dy[3] = {-1, -1, -2};

void solve() {
    int n; cin >> n;
    set<pair<ll, ll>> coords;
    rep(i, 0, n) {
        ll x, y; cin >> x >> y;
        // want the largest y but the smallest x (top left cell)
        coords.emplace(-y, x);
    }
    while (sz(coords) > 1) {
        cout << sz(coords) << "\n";
        if (sz(coords) >= 20) break;
        // remove the top left cell
        // simulate the reversible process
        // this top left cell will keep improving in lexicographical order
        auto [negy, x] = *coords.begin();
        
        ll y = -negy;
        coords.erase(coords.begin());
        // flip cells accordingly
        rep(i, 0, 3) {
            ll newx = x + dx[i], newy = y + dy[i];
            auto it = coords.find({-newy, newx});
            if (it == coords.end()) coords.emplace(-newy, newx);
            else coords.erase(it);
        }
    }
    auto [negy, x] = *coords.begin();
    cout << x << " " << -negy << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}