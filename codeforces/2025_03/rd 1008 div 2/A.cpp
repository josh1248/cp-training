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
        ll N, X;
        cin >> N >> X;
        ll acc = 0;
        rep(i, 0, N) {
            int a; cin >> a;
            acc += a;
        }

        ll factors = 1;
        ll z = N;
        while (z > 1) {
            rep(i, 2, z + 1) {
                if (z % i == 0) {
                    factors *= i;
                    z /= i;
                    break;
                }
            }
        }
        if (X * factors == acc) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}