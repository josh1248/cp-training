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

    double c; cin >> c;
    cout << setprecision(9) << fixed;
    c = min(c, 1.0);
    if (c < 1e-8) cout << 0 << "\n";
    else {
        cout << (c / 2) * (c / 2) << "\n";
    }
}