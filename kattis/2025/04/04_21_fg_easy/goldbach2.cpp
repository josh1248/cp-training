#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<bool> sieve(32001, true);

void populate_sieve() {
    sieve[1] = false;
    sieve[2] = true;
    rep(i, 2, 32001) {
        if (!sieve[i]) continue;
        for (int j = 2 * i; j <= 32000; j += i) {
            sieve[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    populate_sieve();
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        vi ok;
        rep(i, 2, x / 2 + 1) {
            if (sieve[i] && sieve[x - i]) ok.push_back(i);
        }

        cout << x << " has " << sz(ok) << " representation(s)\n";
        for (int i: ok) cout << i << "+" << x-i << "\n";
        cout << "\n";
    }
}