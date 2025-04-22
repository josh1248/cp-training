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

    ll prev = 1;
    int n; cin >> n;
    rep(i, 0, n) {
        ll a, b; char op; cin >> a >> op >> b;
        if (op == '*') {
            prev = a * b * a * b;
            cout << prev << "\n";
        } else if (op == '+') {
            prev = a + b - prev;
            cout << prev << "\n";
        } else if (op == '-') {
            prev = (a - b) * prev;
            cout << prev << "\n";
        } else {
            prev = (a + 1) / 2;
            cout << prev << "\n";
        }
    }
}