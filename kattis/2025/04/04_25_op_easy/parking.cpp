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

    vi prices(3);
    rep(i, 0, 3) cin >> prices[i];
    vector<pi> intervals(3);
    rep(i, 0, 3) cin >> intervals[i].first >> intervals[i].second;
    int acc = 0;
    rep(i, 1, 101) {
        int hits = 0;
        rep(j, 0, 3) {
            if (i >= intervals[j].first && i < intervals[j].second) {
                hits++;
            }
        }
        if (hits > 0) acc += hits * prices[hits - 1];
    } 
    cout << acc << "\n";
}