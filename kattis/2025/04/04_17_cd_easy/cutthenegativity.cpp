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

    int n; cin >> n;
    vvi AM(n, vi(n));
    int cnt = 0;
    rep(r, 0, n) {
        rep(c, 0, n) {
            cin >> AM[r][c];
            if (AM[r][c] != -1) cnt++;
        }
    }
    cout << cnt << "\n";
    rep(r, 0, n) {
        rep(c, 0, n) {
            if (AM[r][c] != -1) {
                cout << r + 1 << " " << c + 1 << " " << AM[r][c] << "\n";
            }
        }
    }
}