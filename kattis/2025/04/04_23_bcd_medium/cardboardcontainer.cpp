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

    int V; cin >> V;
    int best = 1e9;
    rep(x, 1, 101) {
        if (V % x != 0) continue;
        int target = V / x;
        rep(f, 1, target + 1) {
            if (target % f == 0) {
                int h = target / f;
                best = min(best, 2 * (x * f + f * h + h * x));
            }
        }
    }
    cout << best << "\n";
}