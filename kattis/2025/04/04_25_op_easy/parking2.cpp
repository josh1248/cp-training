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
        int k; cin >> k;
        vi v(k);
        rep(i, 0, k) cin >> v[i];
        if (sz(v) == 1) cout << 0 << "\n";
        else {
            sort(all(v));
            cout << 2 * (v[sz(v) - 1] - v[0]) << "\n";
        }
    }
}