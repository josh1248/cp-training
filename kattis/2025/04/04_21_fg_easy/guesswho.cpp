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

    int n, m, q; cin >> n >> m >> q;
    vector<string> candidates(n);
    rep(i, 0, n) cin >> candidates[i];
    string match(m, 'X');
    rep(i, 0, q) {
        int x; cin >> x >> match[x - 1];
    }
    vi ok;
    rep(i, 0, n) {
        bool hit = true;
        rep(j, 0, m) {
            if (match[j] == 'X') continue;
            else if (match[j] == candidates[i][j]) continue;
            else hit = false;
        }
        if (hit) ok.push_back(i);
    }
    if (sz(ok) == 1) {
        cout << "unique\n";
        cout << ok[0] + 1 << "\n";
    } else {
        cout << "ambiguous\n";
        cout << sz(ok) << "\n";
    }
}