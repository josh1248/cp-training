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
    cout << setprecision(8) << fixed;
    rep(i, 0, t) {
        int x, y; cin >> x >> y;
        double lo = 0, hi = 0.50 * min(x, y);
        while (hi - lo > 1e-9) {
            double mid1 = lo + (hi - lo) / 3.0;
            double mid2 = hi - (hi - lo) / 3.0;
            // ternary search
            double amid1 = (x - mid1 - mid1) * (y - mid1 - mid1) * mid1;
            double amid2 = (x - mid2 - mid2) * (y - mid2 - mid2) * mid2;
            if (amid1 < amid2) {
                lo = mid1;
            } else {
                hi = mid2;
            }
        }
        cout << (x - lo - lo) * (y - lo - lo) * lo << "\n";
    }
}