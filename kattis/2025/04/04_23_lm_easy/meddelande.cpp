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

    int r, c; cin >> r >> c;
    vector<string> grid(r);
    rep(i, 0, r) cin >> grid[i];
    rep(i, 0, r) {
        rep(j, 0, c) {
            if (grid[i][j] != '.') cout << grid[i][j];
        }
    }
    cout << "\n";
}