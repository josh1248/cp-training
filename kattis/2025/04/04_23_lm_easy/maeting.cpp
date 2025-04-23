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

    int m, n; cin >> m >> n;
    vi v(m);
    rep(i, 0, m) cin >> v[i];
    unordered_set<int> s;
    rep(i, 0, n) {
        int x; cin >> x;
        s.insert(x);
    }
    for (int i: v) {
        if (s.count(i) > 0) cout << i << " ";
    }
    cout << "\n";
}