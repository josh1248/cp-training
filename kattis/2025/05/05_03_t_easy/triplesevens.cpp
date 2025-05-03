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
    vector<bool> ok(3);
    rep(i, 0, 3) {
        rep(j, 0, n) {
            int x; cin >> x;
            if (x == 7) ok[i] = true;
        }
    }
    if (ok[0] && ok[1] && ok[2]) cout << 777 << "\n";
    else cout << 0 << "\n";
}