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

    int C, R; cin >> C >> R;
    vector<string> grid(R);
    rep(i, 0, R) cin >> grid[i];
    int empties = 0;
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (grid[i][j] == '.') empties++;
        }
    }
    cout << setprecision(10) << fixed;
    cout << 1.0 * empties / (R * C) << "\n";
}