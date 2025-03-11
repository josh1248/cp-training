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
    int t; cin >> t;
    while (t--) {
        ll n, k, p; cin >> n >> k >> p;
        p = abs(p);
        k = abs(k);
        if (k == 0) {
            cout << 0 << "\n";
            continue;
        }

        if (n * p < k) {
            cout << -1 << "\n";
        } else {
            cout << (p + k - 1) / p << "\n";
        }
    }
}