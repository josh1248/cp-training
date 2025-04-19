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

    
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        // true -> desired parity at that bit reached
        // false -> not reached
        vector<bool> wanted_parity(31, true); 
        rep(i, 0, 31) {
            if (x & (1ll << i)) wanted_parity[i] = false;
        }
        rep(j, 1, x + 1) {
            rep(p, 0, 31) {
                if (j & (1ll << p)) wanted_parity[p] = !wanted_parity[p];
            }
        }

        if (all_of(all(wanted_parity), [](bool b){ return b; })) {
            cout << x << "\n";
            rep(i, 1, x + 1) cout << i << " ";
            cout << "\n";
        } else {
            cout << x - 1 << "\n";
            int acc = 0;
            rep(i, 0, 31) {
                if (!wanted_parity[i]) acc += (1 << i);
            }
            rep(i, 1, x + 1) {
                if (i != acc) cout << i << " ";
            }
            cout << "\n";
        }
    }
}