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
    rep(i, 0, r) {
        cin >> grid[i];
    }

    vi cnts(5);
    rep(i, 0, r - 1) {
        rep(j, 0, c - 1) {
            if (grid[i][j] == '#' || grid[i + 1][j] == '#' || grid[i][j + 1] == '#' || grid[i + 1][j + 1] == '#') {
                continue;
            }

            int cnt = 0;
            if (grid[i][j] == 'X') cnt++;
            if (grid[i+1][j] == 'X') cnt++;
            if (grid[i][j+1] == 'X') cnt++;
            if (grid[i+1][j+1] == 'X') cnt++;
            cnts[cnt]++;
        }
    }
    for (int i: cnts) cout << i << "\n";
}