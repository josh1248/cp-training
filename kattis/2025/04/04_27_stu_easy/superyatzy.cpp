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

    vi cnts(6, 0);
    int n, m; cin >> n >> m;
    rep(i, 0, n) {
        int x; cin >> x;
        cnts[x - 1]++;
    }
    int hi = -1;
    rep(i, 0, 6) {
        hi = max(hi, cnts[i]);
    }
    cout << (n - hi <= m ? "Ja" : "Nej") << "\n";
}