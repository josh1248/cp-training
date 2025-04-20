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

    int x1, y1, x2, y2, x, y;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    cout << setprecision(9) << fixed;
    int dx, dy;
    if (x >= x1 && x <= x2) dx = 0;
    else if (x < x1) dx = x1 - x;
    else dx = x - x2;
    
    if (y >= y1 && y <= y2) dy = 0;
    else if (y < y1) dy = y1 - y;
    else dy = y - y2;
    cout << pow(pow(dx, 2) + pow(dy, 2), 0.5) << "\n";
}