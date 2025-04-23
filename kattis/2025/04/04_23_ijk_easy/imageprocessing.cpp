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

    int gr, gc, kr, kc; cin >> gr >> gc >> kr >> kc;
    vvi grid(gr, vi(gc));
    rep(i, 0, gr) {
        rep(j, 0, gc) {
            cin >> grid[i][j];
        }
    }
    vvi kernel(kr, vi(kc));
    rep(i, 0, kr) {
        rep(j, 0, kc) {
            cin >> kernel[i][j];
        }
    }
    vvi out(gr - kr + 1, vi(gc - kc + 1));
    rep(i, 0, gr - kr + 1) {
        rep(j, 0, gc - kc + 1) {
            rep(k, 0, kr) {
                rep(l, 0, kc) {
                    out[i][j] += kernel[kr - k - 1][kc - l - 1] * grid[i + k][j + l];
                }
            }
        }
    }

    rep(i, 0, gr - kr + 1) {
        rep(j, 0, gc - kc + 1) {
            cout << out[i][j] << " ";
        }
        cout << "\n";
    }
}