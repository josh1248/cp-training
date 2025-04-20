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

    vector<ll> fibs(100001, 2e18);
    fibs[1] = fibs[2] = 1;
    rep(i, 3, 100001) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
        if (fibs[i] > 2e18) {
            fibs[i] = 2e18;
            break;
        }
    }

    ll n, k; cin >> n >> k;
    while (true) {
        if (n == 1) {
            cout << "N\n";
            return 0;
        } else if (n == 2) {
            cout << "A\n";
            return 0;
        } else {
            // am i within the substring in fibs[n - 1] or fibs[n - 2]?
            if (k <= fibs[n - 2]) {
                // inside n - 2
                n -= 2;
            } else {
                // inside n - 1, cut out n - 2
                k -= fibs[n - 2];
                n -= 1;
            }
        }
    }
}