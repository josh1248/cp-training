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

    int n, m; cin >> n >> m;
    vi res(n);
    ll evens = 0;
    ll ans = 0;
    rep(i, 0, n) {
        cin >> res[i];
    }
    rep(i, 0, m - 1) {
        if (res[i] % 2 == 0) evens++;
    }
    rep(i, m - 1, n) {
        if (res[i] % 2 == 0) evens++;
        if (evens >= 2) ans++;
        if (res[i - m + 1] % 2 == 0) evens--;
    }
    cout << ans << "\n";
}