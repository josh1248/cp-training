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

    int n, r, c; cin >> n >> r >> c;
    vector<vector<string>> g(r, vector<string>(c));
    rep(i, 0, r) {
        rep(j, 0, c) {
            cin >> g[i][j];
        }
    }
    rep(i, 0, r) {
        string s;
        rep(j, 0, c) cin >> s;
        if (s == g[i][0]) cout << "right\n";
        else cout << "left\n";
    }
}