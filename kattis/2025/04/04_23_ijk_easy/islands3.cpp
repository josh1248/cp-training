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
    int min_cc = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    rep(i, 0, r) {
        rep(j, 0, c) {
            if (grid[i][j] == 'L') {
                min_cc++;
                vector<pi> stack;
                stack.emplace_back(i, j);
                while (sz(stack) > 0) {
                    auto [x, y] = stack.back(); stack.pop_back();
                    grid[x][y] = 'X';
                    rep(k, 0, 4) {
                        int newx = x + dx[k], newy = y + dy[k];
                        if (newx < 0 || newx >= r || newy < 0 || newy >= c
                            || grid[newx][newy] == 'W' || grid[newx][newy] == 'X') continue;
                        stack.emplace_back(newx, newy); 
                    }
                }
            }
        }
    }
    cout << min_cc << "\n";
}