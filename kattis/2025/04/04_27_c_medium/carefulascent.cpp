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

    int x, y; cin >> x >> y;
    int n; cin >> n;
    int unaffected = y;
    double affected = 0;
    rep(i, 0, n) {
        int l, u; double f;
        cin >> l >> u >> f;
        unaffected -= (u - l);
        affected += f * (u - l);
    }
    cout << setprecision(8) << fixed;
    cout << 1.0 * x / (unaffected + affected) << "\n";
}