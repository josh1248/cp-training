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

    int v;
    while (cin >> v) {
        if (v == -1) return 0;
        vvi AM(v, vi(v));
        rep(i, 0, v) {
            rep(j, 0, v) {
                cin >> AM[i][j];
            }
        }
        vi ans;
        rep(i, 0, v) {
            bool ok = false;
            rep(j, 0, v) {
                if (ok) break;
                rep(k, 0, v) {
                    if (i == j || i == k || j == k) continue;
                    if (AM[i][j] && AM[i][k] && AM[j][k]) {
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok) ans.push_back(i);
        }
        for (int i: ans) cout << i << " ";
        cout << "\n";
    }
}