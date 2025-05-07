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

    int R, C; cin >> R >> C;
    vvi grid(R, vi(C, 0));
    vector<vector<bool>> in(R, vector<bool>(C, false));
    int X; cin >> X;
    rep(i, 0, X) {
        int x, y; cin >> x >> y;
        --x, --y;
        in[x][y] = true;
        rep(j, 0, 8){
            int adjx = x + dx[j], adjy = y + dy[j];
            if (adjx < 0 || adjx >= R || adjy < 0 || adjy >= C) continue;
            grid[adjx][adjy]++;
        }
    }

    vi hits(9);
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (!in[i][j]) continue;
            hits[grid[i][j]]++;
        }
    }
    for (int i: hits) cout << i << " ";
    cout << "\n";
}