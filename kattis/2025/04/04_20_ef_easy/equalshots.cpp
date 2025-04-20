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

    int x, y; cin >> x >> y;
    int acc_x = 0, acc_y = 0;
    rep(i, 0, x) {
        int a, b; cin >> a >> b;
        acc_x += a * b;
    }
    rep(i, 0, y) {
        int a, b; cin >> a >> b;
        acc_y += a * b;
    }
    cout << (acc_x == acc_y ? "same" : "different") << "\n";
}