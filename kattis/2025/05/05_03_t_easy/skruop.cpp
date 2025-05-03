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

    int t, n; cin >> t; n = 7;
    string flush, s;
    rep(i, 0, t) {
        cin >> flush >> s;
        if (s == "op!") n = min(n + 1, 10);
        else n = max(n - 1, 0);
    }
    cout << n << "\n";
}