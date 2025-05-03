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

    int X; cin >> X;
    vector<string> grid(X);
    rep(i, 0, X) cin >> grid[i];
    bool ok = true;
    int want = X / 2;
    rep(i, 0, X) {
        int cnt = 0;
        rep(j, 0, X) {
            if (grid[i][j] == 'W') cnt++;
        }
        if (cnt != want) ok = false;
    }
    rep(i, 0, X) {
        int cnt = 0;
        rep(j, 0, X) {
            if (grid[j][i] == 'W') cnt++;
        }
        if (cnt != want) ok = false;
    }
    rep(i, 0, X) {
        char prev = 'X';
        int consecs = 0;
        rep(j, 0, X) {
            if (grid[i][j] == prev) {
                consecs++;
            } else {
                consecs = 1;
            }
            prev = grid[i][j];
            if (consecs == 3) ok = false;
        }
    }
    rep(i, 0, X) {
        char prev = 'X';
        int consecs = 0;
        rep(j, 0, X) {
            if (grid[j][i] == prev) {
                consecs++;
            } else {
                consecs = 1;
            }
            prev = grid[j][i];
            if (consecs == 3) ok = false;
        }
    }
    cout << (ok ? 1 : 0) << "\n";
}