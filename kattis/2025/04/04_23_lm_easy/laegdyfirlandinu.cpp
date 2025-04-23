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
    vvi grid(R, vi(C));
    rep(i, 0, R) {
        rep(j, 0, C) {
            cin >> grid[i][j];
        }
    }
    bool lopressure = false;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    rep(i, 1, R - 1) {
        rep(j, 1, C - 1) {
            bool lo = true;
            rep(k, 0, 4) {
                int newx = i + dx[k], newy = j + dy[k];
                if (grid[i][j] >= grid[newx][newy]) lo = false;
            } 
            if (lo) lopressure = true;
        }
    }
    cout << (lopressure ? "Jebb" : "Neibb") << "\n";
}