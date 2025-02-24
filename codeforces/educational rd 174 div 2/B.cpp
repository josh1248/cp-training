#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

void solve() {
    int R, C; cin >> R >> C;
    int grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    // count steps to remove a specific color
    // pick target colour = colour with most steps to get out of
    // result = sum of steps - most tedious colour
    // can convert within 2 steps (checkerboard)
    vi steps(R * C + 1, 0);
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int color = grid[i][j];
            bool flag = false;
            for (int x = 0; x < 4; x++) {
                int test_r = i + dr[x], test_c = j + dc[x];
                if (test_r < 0 || test_r >= R || test_c < 0 || test_c >= C) {
                    continue;
                }
                if (grid[test_r][test_c] == color) {
                    flag = true;
                }
            }
            steps[color] = max(steps[color], (flag ? 2 : 1));
        }
    }

    bool has_2_flag = false;
    int total_steps = 0;
    for (int i: steps) {
        if (i == 2) {
            has_2_flag = true;
        }
        total_steps += i;
    }

    cout << total_steps - (has_2_flag ? 2 : 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}