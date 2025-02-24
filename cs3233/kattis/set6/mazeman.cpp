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
    
    string dummy; getline(cin, dummy);
    rep (i, 0, R) {
        getline(cin, grid[i]);
    }

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int dots_remaining = 0, total_dots = 0;
    for (string& s: grid) {
        for (char c: s) {
            if (c == '.') total_dots++;
        }
    }
    dots_remaining = total_dots;

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    function<int(int, int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c]) {
            return 0;
        }
        if (!(grid[r][c] == '.' || grid[r][c] == ' ')) {
            return 0;
        }

        int hits = 0;
        visited[r][c] = true;
        if (grid[r][c] == '.') {
            dots_remaining--;
            hits++;
        }
        
        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i], new_c = c + dc[i];
            hits += dfs(new_r, new_c);
        }
        return hits;
    };

    int used = 0;
    bool flag = false;
    for (int i = 1; i < C - 1; i++) {
        if (flag) break;
        if (grid[0][i] != 'X') {
            if (visited[1][i]) continue;
            if (dfs(1, i)) used++;
            if (dots_remaining == 0) flag = true;
        }

        if (grid[R - 1][i] != 'X') {
            if (visited[R - 2][i]) continue;
            if (dfs(R - 2, i)) used++;
            if (dots_remaining == 0) flag = true;
        }
    }

    for (int i = 1; i < R - 1; i++) {
        if (flag) break;
        if (grid[i][0] != 'X') {
            if (visited[i][1]) continue;
            if (dfs(i, 1)) used++;
            if (dots_remaining == 0) flag = true;
        }

        if (grid[i][C - 1] != 'X') {
            if (visited[i][C - 2]) continue;
            if (dfs(i, C - 2)) used++;
            if (dots_remaining == 0) flag = true;
        }
    }

    if (dots_remaining == total_dots) {
        cout << 0 << " " << dots_remaining << "\n";
    } else {
        cout << used << " " << dots_remaining << "\n";
    }
}