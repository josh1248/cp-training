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

    int r, c, zr, zc; cin >> r >> c >> zr >> zc;
    vector<vector<char>> grid(r * zr, vector<char>(c * zc, '?'));
    vector<string> org(r);
    rep(i, 0, r) cin >> org[i];
    rep(i, 0, r) {
        rep(j, 0, c) {
            rep(k, 0, zr) {
                rep(l, 0, zc) {
                    grid[i * zr + k][j * zc + l] = org[i][j];
                }
            }
        }
    }
    rep(i, 0, r * zr) {
        rep(j, 0, c * zc) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}