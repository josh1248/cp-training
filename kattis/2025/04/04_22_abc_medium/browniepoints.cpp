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

    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        vector<pi> coords(n);
        rep(i, 0, n) cin >> coords[i].first >> coords[i].second;
        auto [xcheck, ycheck] = coords[n / 2];
        int q13 = 0, q24 = 0;
        for (auto& [x, y]: coords) {
            if (x == xcheck || y == ycheck) continue;
            else if (x > xcheck && y > ycheck) q13++;
            else if (x < xcheck && y < ycheck) q13++;
            else q24++;
        }
        cout << q13 << " " << q24 << "\n";
    }
}