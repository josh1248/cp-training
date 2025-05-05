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

    int l, r, x; cin >> l >> r >> x;
    rep(i, l, r + 1) {
        int digitsum = 0;
        int curr = i;
        while (curr > 0) {
            digitsum += curr % 10;
            curr /= 10;
        }
        if (digitsum == x) {
            cout << i << "\n";
            break;
        }
    }

    for (int i = r; i >= l; i--) {
        int digitsum = 0;
        int curr = i;
        while (curr > 0) {
            digitsum += curr % 10;
            curr /= 10;
        }
        if (digitsum == x) {
            cout << i << "\n";
            break;
        }
    }
}