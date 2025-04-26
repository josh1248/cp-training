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
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    int base = v[0];
    rep(i, 1, n) {
        int l = base / gcd(v[0], v[i]), r = v[i] / gcd(v[0], v[i]);
        cout << l << "/" << r << "\n";
    }
}