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

    int R = 7, C = 7;
    vector<string> grid(7);
    rep(i, 0, 7) getline(cin, grid[i]);
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int hits = 0;
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (grid[i][j] != '.') continue;
            rep(k, 0, 4) {
                int newx = i + dx[k], newy = j + dy[k],
                    newx2 = i + 2 * dx[k], newy2 = j + 2 * dy[k];        
                if (newx2 < 0 || newx2 >= R || newy2 < 0 || newy2 >= C) continue;
                if (grid[newx][newy] == 'o' && grid[newx2][newy2] == 'o') {
                    hits++;
                }
            }
        }
    }
    cout << hits << "\n";
}