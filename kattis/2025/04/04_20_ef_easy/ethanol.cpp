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

    int X; cin >> X;
    rep(i, 0, 2 * X + 1) {
        cout << ((i != 0 && i % 2 == 0) ? 'H' : ' ');
    }
    cout << "\n";
    rep(i, 0, 2 * X + 1) {
        cout << ((i != 0 && i % 2 == 0) ? '|' : ' ');
    }
    cout << "\n";
    rep(i, 0, 2 * X + 4) {
        if (i == 0 || i == 2 * X + 3) cout << 'H';
        else if (i == 2 * X + 2) cout << 'O';
        else if (i % 2 == 0) cout << 'C';
        else cout << '-';
    }
    cout << "\n";
    rep(i, 0, 2 * X + 1) {
        cout << ((i != 0 && i % 2 == 0) ? '|' : ' ');
    }
    cout << "\n";
    rep(i, 0, 2 * X + 1) {
        cout << ((i != 0 && i % 2 == 0) ? 'H' : ' ');
    }
    cout << "\n";
}