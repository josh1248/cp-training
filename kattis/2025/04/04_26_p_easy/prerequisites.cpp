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

    int k;
    while (cin >> k) {
        if (k == 0) return 0;
        int m; cin >> m;
        vector<bool> coursetaken(10000, false);
        rep(i, 0, k) {
            int x; cin >> x;
            coursetaken[x] = true;
        }
        bool ok = true;
        rep(i, 0, m) {
            int c, r; cin >> c >> r;
            rep(j, 0, c) {
                int curr; cin >> curr;
                if (coursetaken[curr]) r--;
            }
            if (r > 0) ok = false;
        }
        cout << (ok ? "yes" : "no") << "\n";
    }
}