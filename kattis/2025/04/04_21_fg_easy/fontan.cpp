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

    int R, C; cin >> R >> C;
    vector<string> grid(R);
    rep(i, 0, R) cin >> grid[i];
    function<void(int, int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C) return;
        else if (grid[r][c] != 'V') return;
        if (r + 1 < R && grid[r + 1][c] == '#') {
            if (c > 0 && grid[r][c - 1] == '.') {
                grid[r][c - 1] = 'V';
                dfs(r, c - 1);
            }
            if (c + 1 < C && grid[r][c + 1] == '.') {
                grid[r][c + 1] = 'V';
                dfs(r, c + 1);
            }
        } else if (r + 1 < R && grid[r + 1][c] == '.') {
            grid[r + 1][c] = 'V';
            dfs(r + 1, c);
        }
    };
    rep(i, 0, R) { 
        rep(j, 0, C) {
            dfs(i, j);
        }
    }
    for (string s: grid) cout << s << "\n";
}