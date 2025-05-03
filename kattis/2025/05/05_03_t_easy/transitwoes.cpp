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

    int s, t, n; cin >> s >> t >> n;
    vi walks(n + 1);
    rep(i, 0, n + 1) cin >> walks[i];
    vi bustime(n), busintervals(n);
    rep(i, 0, n) cin >> bustime[i];
    rep(i, 0, n) cin >> busintervals[i];
    int timenow = 0;
    rep(i, 0, n) {
        timenow += walks[i];
        if (timenow % busintervals[i] != 0) {
            timenow = timenow - (timenow % busintervals[i]) + busintervals[i];
        }
        timenow += bustime[i];
    }
    timenow += walks[n];
    cout << (timenow <= t ? "yes" : "no") << "\n";
}