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

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << setprecision(9) << fixed;
    double furthest = 0;
    furthest = max(furthest, pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5));
    furthest = max(furthest, pow(pow(x3 - x4, 2) + pow(y3 - y4, 2), 0.5));
    cout << furthest << "\n";
}