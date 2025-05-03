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

    cout << setprecision(10) << fixed;
    int t; cin >> t;
    rep(i, 0, t) {
        int n; cin >> n;
        double bearing = 90, x = 0, y = 0;
        rep(j, 0, n) {
            double b, d; cin >> b >> d;
            bearing = remainder(360.0 + bearing + b, 360.0);
            x += d * cos(bearing / 180 * M_PI);
            y += d * sin(bearing / 180 * M_PI);
        }
        cout << x << " " << y << "\n";
    }
}