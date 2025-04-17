#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define int long long
#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<bool> is_prime(1001, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int f = 2; f <= 1000; f++) {
        if (is_prime[f]) {
            for (int g = 2 * f; g <= 1000; g += f) {
                is_prime[g] = false;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    int t; cin >> t;
    while (t--) {
        int d, e; cin >> d >> e;
        int p, q;
        bool done = false;
        rep(i, 2, 1001) {
            if (done) break;
            rep(j, i + 1, 1001) {
                if (!is_prime[i] || !is_prime[j]) continue;
                else if (i * j == d) {
                    p = i, q = j;
                    done = true;
                    break;
                }  
            }
        }
        int totient = (p - 1) * (q - 1);
        int ans = 1;
        while (true) {
            if (ans * e % totient == 1) {
                cout << ans << "\n";
                break;
            }
            ans++;
        }
    }
}