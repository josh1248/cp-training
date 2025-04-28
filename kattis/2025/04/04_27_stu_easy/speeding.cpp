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
    int prevt, prevd; cin >> prevt >> prevd;
    double best = 0;
    rep(i, 0, t - 1) {
        int currt, currd; cin >> currt >> currd;
        double avg = 1.0 * (currd - prevd) / (currt - prevt);
        best = max(best, avg);
        prevt = currt, prevd = currd;
    }
    cout << int(best) << "\n";
}