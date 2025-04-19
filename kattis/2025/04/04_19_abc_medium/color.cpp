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

    ll s, c, k; cin >> s >> c >> k;
    vector<ll> socks(s);
    rep(i, 0, s) cin >> socks[i];
    sort(all(socks));
    ll res = 1;
    ll curr_cap = c;
    ll prev_color = socks[0];
    for (ll sock: socks) {
        if (curr_cap == 0 || (sock - prev_color > k)) {
            curr_cap = c - 1;
            res++;
            prev_color = sock;
        } else {
            curr_cap--;
        }
    }
    cout << res << "\n";
}