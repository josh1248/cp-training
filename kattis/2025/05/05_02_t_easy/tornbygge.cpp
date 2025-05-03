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

    int t; cin >> t;
    int prev = -1;
    int ans = 0;
    rep(i, 0, t) {
        int x; cin >> x;
        if (x > prev) {
            ans++;
        }
        prev = x;
    }
    cout << ans << "\n";
}