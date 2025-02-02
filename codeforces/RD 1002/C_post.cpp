#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

void solve() {
    int n; cin >> n;
    vvi data(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> data[i][j];
        }
    }

    multiset<int> streaks;

    // use constraint that every number must be >= 1
    // to have numbers 0 to i:
    // must service any queue at the end
    // must service a queue with 1 customer at end - 1
    // must service a queue with .... 1 1 at end - 2
    // if streak of 1's broken, like .... 3 1 1, then we know that queue cannot serve as 3 or larger.
    // (IF it did, suppose service the queue ... 3 1 1 at end - 3,
    // then there is no queue with 3 customers at the end.)
    for (int i = 0; i < n; i++) {
        int streak = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (data[i][j] == 1) {
                streak++;
            } else {
                break;
            }
        }
        streaks.insert(streak);
    }

    int mex = 0;
    for (int i: streaks) {
        if (i < mex) {
            continue;
        }
        mex++;
    }
    cout << mex << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}