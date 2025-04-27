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

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    int r, c; cin >> r >> c;
    vector<string> grid(r);
    rep(i, 0, r) cin >> grid[i];

    int cc = 0;
    rep(i, 0, r) {
        rep(j, 0, c) {
            if (grid[i][j] == '#') {
                cc++;
                vector<pi> stack;
                stack.emplace_back(i, j);
                while (sz(stack) > 0) {
                    auto [x, y] = stack.back(); stack.pop_back();
                    grid[x][y] = 'X';
                    rep(k, 0, 8) {
                        int newx = x + dx[k], newy = y + dy[k];
                        if (newx < 0 || newx >= r || newy < 0 || newy >= c) continue;
                        if (grid[newx][newy] == '#') {
                            stack.emplace_back(newx, newy);
                        }
                    }
                }
            }
        }
    }
    cout << cc << "\n";
}