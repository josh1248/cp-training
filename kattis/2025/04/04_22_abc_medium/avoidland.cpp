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

    int n; cin >> n;
    vi rowcnts(n), colcnts(n);
    rep(i, 0, n) {
        int r, c; cin >> r >> c;
        --r, --c;
        rowcnts[r]++, colcnts[c]++;
    }

    // first, determine how to distribute rowcnts to [1,1,1...]
    // this wont affect col positions, so we can solve independently
    function<ll(vi&)> moves = [&](vi& histogram) {
        ll curr_req = 0;
        ll res = 0;
        rep(i, 0, sz(histogram)) {
            if (histogram[i] == 0) continue;
            rep(j, 0, histogram[i]) {
                res += abs(i - curr_req++);
            }
        }
        return res;
    };

    cout << moves(rowcnts) + moves(colcnts) << "\n";
}