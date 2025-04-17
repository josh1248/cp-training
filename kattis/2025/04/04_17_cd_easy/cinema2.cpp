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
    int left, n; cin >> left >> n;
    rep(i, 0, n) {
        int x; cin >> x;
        if (left - x >= 0) {
            left -= x;
        } else {
            cout << n - i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}