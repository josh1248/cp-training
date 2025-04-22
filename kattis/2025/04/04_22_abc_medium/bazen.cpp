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

    // total area = 250^2 / 2 = 31250
    // we need to make a triangle with w * h = 31250 to cut to half
    int x, y; cin >> x >> y;
    cout << setprecision(2) << fixed;
    if (x == 0) {
        // on vertical line
        // Case 1: b <= 125
        // take upper triangle with w = 250 - b
        // then required h = 31250 / (250 - b) < 250 on diagonal
        // with y coordinate 250 - h
        if (y <= 125) {
            double h = 31250.0 / (250 - y);
            cout << h << " " << 250 - h << "\n";
        } else {
            // Case 2: b > 125
            // then take lower triangle with w = b,
            // and required h = 31250 / b < 250 on horizontal line
            // with y coordinate 0
            double h = 31250.0 / y;
            cout << h << " 0.00" << "\n";
        }
        return 0;
    }

    if (y == 0) {
        // on horizontal line
        if (x <= 125) {
            double h = 31250.0 / (250 - x);
            cout << 250 - h << " " << h <<"\n";
        } else {
            double h = 31250.0 / x;
            cout << "0.00 " << h << "\n";
        }
        return 0;
    }


    // line is on diagonal
    if (x >= 125) {
        // Case 1: x >= 125
        // let this be height, then the width on vertical line is
        // 31250 / x at the top portion
        cout << "0.00 " << 250.0 - (31250.0 / x) << "\n";
    } else {
        // Case 2: y > 125
        // let this be height, then the width on horizontal line is
        // 31250 / y at the right portion
        cout << 250.0 - (31250.0 / y) << " 0.00" << "\n";
    }

}