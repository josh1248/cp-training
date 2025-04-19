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

    ll k, m, n; cin >> k >> m >> n;
    if (k < m) cout << "Barb\n";
    else if (k <= n) cout << "Alex\n";
    else {
        // Alex must take out some marbles to be in the win territory for player B
        // so the win regions alternate now:
        // [n + 1 to n + m] for B
        // [n + m + 1 to n + 2m] for A
        // and so on.
        ll r = k % (m + n);
        if (r < m) cout << "Barb\n";
        else cout << "Alex\n";
    }
}