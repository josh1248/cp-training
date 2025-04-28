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

    int t; cin >> t;
    cout << setprecision(9) << fixed;
    int prevtime; double prevheight; cin >> prevtime >> prevheight;
    double res = 0;
    rep(i, 0, t - 1) {
        int currtime; double currheight; cin >> currtime >> currheight;
        res += (currtime - prevtime) * 1.0 * (currheight + prevheight) / 2;
        prevtime = currtime, prevheight = currheight;
    }
    cout << res / 1000 << "\n";
}