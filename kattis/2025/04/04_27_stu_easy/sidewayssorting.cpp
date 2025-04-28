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

    int r, c;
    while (cin >> r >> c) {
        if (r == 0 && c == 0) return 0;
        vector<string> grid(r);
        rep(i, 0, r) cin >> grid[i];
        vector<pair<string, string>> k;
        rep(j, 0, c) {
            string x = "";
            string xk = "";
            rep(i, 0, r) {
                x.append(1, grid[i][j]);
                xk.append(1, tolower(grid[i][j]));
            }
            k.emplace_back(xk, x);
        }
        stable_sort(all(k));
        vector<vector<char>> ans(r, vector<char>(c, '.'));
        rep(j, 0, c) {
            auto& [xk, x] = k[j];
            rep(i, 0, r) {
                ans[i][j] = x[i];
            }
        }

        rep(i, 0, r) {
            rep(j, 0, c) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}