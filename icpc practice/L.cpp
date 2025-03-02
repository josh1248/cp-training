#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c,n,p;cin>>r>>c>>n>>p;
    vvi g(r, vi(c));
    vi meetups;
    rep(i, 0, r) rep(j, 0, c) cin >> g[i][j];
    rep(i, 0, r) rep(j, 0, c) if (g[i][j] != 0 && g[i][j] <= p) {
        if (0 < i && g[i-1][j] != 0) {
            meetups.push_back(g[i - 1][j] - g[i][j]);
        }
        if (i < r - 1 && g[i+1][j] != 0) {
            meetups.push_back(g[i + 1][j] - g[i][j]);
        }
        if (0 < j && g[i][j-1] != 0) {
            meetups.push_back(g[i][j - 1] - g[i][j]);
        }
        if (j < c - 1 && g[i][j+1] != 0) {
            meetups.push_back(g[i][j + 1] - g[i][j]);
        }
    }
    sort(all(meetups));
    int ans = 0;
    for (int i = 0; i < sz(meetups); i++) {
        if (i > 0 && meetups[i-1] == meetups[i]) continue;
        if (meetups[i] + p < 1 || meetups[i] + p > n) continue;
        ans++;
    }
    cout << ans << '/' << n - 1 << '\n';
}