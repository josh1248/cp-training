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
        int n; cin >> n;
        vi v(n);
        rep(i, 0, n) cin >> v[i];
        int diff = v[1] - v[0];
        bool ok = true;
        rep(i, 1, n) {
            if (v[i] - v[i - 1] != diff) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "arithmetic\n";
            continue;
        }
        sort(all(v));
        diff = v[1] - v[0];
        ok = true;
        rep(i, 1, n) {
            if (v[i] - v[i - 1] != diff) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "permuted arithmetic\n";
        } else {
            cout << "non-arithmetic\n";
        }
    }
}