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
    vi rows(R), cols(C);
    rep(i, 0, R) cin >> rows[i];
    rep(i, 0, C) cin >> cols[i];
    int maxr = -1, maxc = -1;
    rep(i, 0, R) maxr = max(maxr, rows[i]);
    rep(i, 0, C) maxc = max(maxc, cols[i]);

    cout << (maxr == maxc ? "possible" : "impossible") << "\n";
}