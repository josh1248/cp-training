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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x, y;
    if (x1 != x2 && x1 != x3) x = x1;
    else if (x2 != x1 && x2 != x3) x = x2;
    else x = x3;

    if (y1 != y2 && y1 != y3) y = y1;
    else if (y2 != y1 && y2 != y3) y = y2;
    else y = y3;

    cout << x << " " << y << "\n";
}