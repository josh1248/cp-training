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
    int lowest = 41, d = 0;
    rep(i, 0, n - 2) {
        int m = max(v[i], v[i + 2]);
        if (m < lowest) {
            lowest = m;
            d = i;
        }
    }
    cout << d + 1 << " " << lowest  << "\n";
}