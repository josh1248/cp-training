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

    ll t, c, p; cin >> t >> c >> p;
    ll acc = 0;
    rep(i, 0, t) {
        ll x; cin >> x;
        if (x > c + p) {
            p = c;
            c = x;
            acc++;
        }
    }
    cout << acc << "\n";
}