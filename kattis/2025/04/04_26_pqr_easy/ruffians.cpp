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

    int t; cin >> t;
    while (t--) {
        vvi grid(2, vi(5));
        rep(i, 0, 2) {
            rep(j, 0, 5) {
                cin >> grid[i][j];
            }
        }
        bool ok = false;
        rep(ar, 0, 2) {
            rep(br, 0, 2) {
                if (ar == br) continue;
                rep(ac, 0, 5) {
                    rep(bc, 0, 5) {
                        if (ac == bc) continue;
                        
                        if (grid[ar][ac] == grid[br][bc]) {
                            ok = true;
                        }
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}