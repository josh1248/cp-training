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

    double a, b, c, i, j, k;
    cin >> a >> b >> c >> i >> j >> k;
    cout << setprecision(9) << fixed;

    double qty = min({a / i, b / j, c / k});
    cout << a - qty * i << " " << b - qty * j << " " << c - qty * k << "\n";
}