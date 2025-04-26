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
    rep(p, 0, t) {
        unordered_set<ll> s;
        int x; cin >> x;
        rep(i, 0, x) {
            ll m; cin >> m;
            if (s.count(m) > 0) s.erase(m);
            else s.insert(m);
        }
        cout << "Case #" << p + 1 << ": " << *s.begin() << "\n";
    }
}