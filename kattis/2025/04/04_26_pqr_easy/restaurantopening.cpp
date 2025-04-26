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

    vvi dists(R, vi(C, 0));
    rep(i, 0, R) {
        rep(j, 0, C) {
            rep(k, 0, R) {
                rep(l, 0, C) {
                    dists[k][l] += (abs(k - i) + abs(l - j)) * (grid[i][j]);
                }
            }
        }
    }

    int best = 1e9;
    rep(i, 0, R) {
        rep(j, 0, C) {
            best = min(best, dists[i][j]);
        }
    }
    cout << best << "\n";
}