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

    int n; cin >> n;
    vector<string> digits(n);
    rep(i, 0, n) cin >> digits[i];
    string s; cin >> s;
    ll res = 0;
    while (sz(s) > 0) {
        rep(i, 0, n) {
            if (s.find(digits[i]) != 0) continue;
            res *= n;
            res += i;
            s.erase(0, sz(digits[i]));
            break;
        }
    }
    cout << res << "\n";
}