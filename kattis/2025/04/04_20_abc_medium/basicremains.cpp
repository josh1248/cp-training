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

    int base;
    while (cin >> base) {
        if (base == 0) return 0;
        string p, m; cin >> p >> m;
        ll divisor = 0;
        for (char c: m) {
            divisor *= base;
            divisor += ll(c - '0');
        }
        ll digitmodulo = 1;
        ll ans = 0;
        for (int i = sz(p) - 1; i >= 0; i--) {
            ans = (ans + digitmodulo * (p[i] - '0')) % divisor;
            digitmodulo = (digitmodulo * base) % divisor;
        }

        string res;
        while (ans > 0) {
            res.append(1, ans % base + '0');
            ans /= base;
        }
        reverse(all(res));
        cout << (sz(res) > 0 ? res : "0") << "\n";
    }
}