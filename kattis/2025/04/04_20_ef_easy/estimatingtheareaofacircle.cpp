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

    cout << setprecision(9) << fixed;
    double r; int m, c;
    while (cin >> r >> m >> c) {
        if (r == 0) return 0;
        cout << M_PI * r * r << " " << 4.0 * r * r * c / m << "\n";
    }
}