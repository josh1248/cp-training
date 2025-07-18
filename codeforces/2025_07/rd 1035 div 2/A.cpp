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
        int a, b, x, y; cin >> a >> b >> x >> y;
        int diff = (b - a) / 2;
        if (a > b) {
            if (a == b + 1 && a % 2 == 1) {
                cout << y << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if ((b - a) % 2 == 0) {
            // equal amt of 0 -> 1 and 1 -> 0
            cout << min(x, y) * diff + x * diff << "\n";
        } else if (a % 2 == 0) {
            cout << min(x, y) * (diff + 1) + x * diff << "\n";
        } else {
            cout << min(x, y) * diff + x * (diff + 1) << "\n";
        }
    }
}