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
    while (t--) {
        string x, y; cin >> x >> y; cout << x << "\n" << y << "\n";
        rep(i, 0, sz(x)) {
            cout << (x[i] - y[i] == 0 ? '.' : '*');
        }
        cout << "\n\n";
    }
}