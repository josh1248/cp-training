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
        ll x; cin >> x;
        ll s = x * (x + 1) / 2;
        ll test = round(pow(s, 0.5));
        if (test * test == s) {
            cout << -1 << "\n";
            continue;
        }

        ll total = 0;
        rep(i, 1, x + 1) {
            total += i;
            test = round(pow(total, 0.5));
            if (test * test == total) {
                cout << " " << i + 1 << " " << i;
                i++;
                total += i;
            } else {
                cout << " " << i;
            }
        }
        cout << "\n";
    }
}