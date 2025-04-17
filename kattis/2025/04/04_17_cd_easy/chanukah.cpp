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
    rep(i, 0, n) {
        int x, d; cin >> x >> d;
        cout << x << " ";
        if (d % 2 == 0) {
            cout << d / 2 * (d + 1) + d << "\n";
        } else {
            cout << (d + 1) / 2 * d + d << "\n";
        }
    }
    cout << "\n";
}