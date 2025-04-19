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

    string x, y; cin >> x >> y;
    rep(i, 0, sz(x)) {
        if (i % 2 == 0) {
            cout << char('A' + (26 + x[i] - 'A' - (y[i] - 'A')) % 26);
        } else {
            cout << char('A' + (x[i] - 'A' + y[i] - 'A') % 26);
        }
    }
    cout << "\n";
}