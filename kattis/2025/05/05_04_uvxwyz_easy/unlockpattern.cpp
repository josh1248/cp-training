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

    double dist = 0;
    vector<pi> pts(9);
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            int x; cin >> x;
            pts[x - 1] = {i, j};
        }
    }
    rep(i, 0, 8) {
        auto [x1, y1] = pts[i];
        auto [x2, y2] = pts[i + 1];
        dist += pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
    }
    cout << setprecision(10) << fixed << dist << "\n";
}