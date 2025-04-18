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

    int p, a, b, c, d, n; cin >> p >> a >> b >> c >> d >> n;
    vector<double> prices(n);
    rep(i, 0, n) {
        prices[i] = 1.0 * p * (sin(a * (i + 1) + b) + cos(c * (i + 1) + d) + 2);
    }
    double largest_drop = 0; double highest = -1;
    rep(i, 0, n) {
        largest_drop = max(largest_drop, highest - prices[i]);
        highest = max(highest, prices[i]);
    }
    cout << setprecision(9) << fixed << largest_drop << "\n";
}