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
    vvi grid(r, vi(c));
    rep(i, 0, r) {
        rep(j, 0, c) {
            cin >> grid[i][j];
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vvi estimates(r, vi(c, 1e9));
    priority_queue<tuple<int,int,int>> pq;
    pq.emplace(0, 0, 0);
    estimates[0][0] = 0;
    while (sz(pq) > 0) {
        auto [negw, x, y] = pq.top(); pq.pop();
        int w = -negw;
        if (estimates[x][y] < w) continue;
        if (x == r - 1 && y == c - 1) break;
        rep(i, 0, 4) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx < 0 || newx >= r || newy < 0 || newy >= c) continue;
            int neww = max(w, grid[newx][newy] - grid[x][y]);
            if (estimates[newx][newy] > neww) {
                estimates[newx][newy] = neww;
                pq.emplace(-neww, newx, newy);
            }
        }
    }
    cout << estimates[r - 1][c - 1] << "\n";
}