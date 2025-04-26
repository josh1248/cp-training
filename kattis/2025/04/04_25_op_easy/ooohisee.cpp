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
    int hits = 0, targetr = -1, targetc = -1;
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    rep(i, 1, R - 1) {
        rep(j, 1, C - 1) {
            if (grid[i][j] != '0') continue;
            int neighbors = 0;
            rep(k, 0, 8) {
                if (grid[i + dx[k]][j + dy[k]] == 'O') neighbors++;
            }
            if (neighbors == 8) {
                hits++;
                targetr = i, targetc = j;
            }
        }
    }
    if (hits == 0) {
        cout << "Oh no!\n";
    } else if (hits >= 2) {
        cout << "Oh no! " << hits << " locations\n";
    } else {
        cout << targetr + 1 << " " << targetc + 1 << "\n";
    }
}