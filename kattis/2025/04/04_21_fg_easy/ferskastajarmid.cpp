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
    ll m = -1; string ans = "";
    rep(i, 0, n) {
        string curr; int x, y;
        cin >> curr >> x >> y;
        if (x * y > m) {
            ans = curr;
            m = x * y;
        } else if (x * y == m) {
            ans = min(ans, curr);
        }
    }
    cout << ans << "\n";
}