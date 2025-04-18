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

    double fight; int n;
    while (cin >> fight >> n) {
        if (fight == 0.0 && n == 0) {
            return 0;
        }
        vector<pair<double, double>> hives(n);
        rep(i, 0, n) {
            double x, y; cin >> x >> y;
            hives[i] = {x, y};
        }
        vector<bool> sour(n, false);
        rep(i, 0, n) {
            rep(j, i + 1, n) {
                double dx = hives[i].first - hives[j].first;
                double dy = hives[i].second - hives[j].second;
                if (dx * dx + dy * dy < fight * fight) {
                    sour[i] = sour[j] = true;
                }
            }
        }
        int cnt = 0;
        rep(i, 0, n) {
            if (sour[i]) cnt++;
        }
        cout << cnt << " sour, " << n - cnt << " sweet\n";
    }
}