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

    string x, op, y;
    cin >> x >> op >> y;
    if (op == "+") {
        if (sz(x) == sz(y)) {
            cout << 2 << x.substr(1) << "\n";
        } else {
            rep(i, 0, max(sz(x), sz(y))) {
                if (i == 0 || i == max(sz(x), sz(y)) - min(sz(x), sz(y))) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
        }
        cout << "\n";
    } else {
        cout << 1;
        string s(int(sz(x) + sz(y) - 2), '0');
        cout << s << "\n";
    }
}