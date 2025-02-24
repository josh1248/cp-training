#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

void solve() {
    int n; cin >> n;
    vi data(n);
    vi counts(n + 1);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        data[i] = k;
        counts[k]++;
    }
    for (int i = 0; i < n; i++) {
        data[i] = (counts[data[i]] == 1 ? 1 : 0);
    }

    // find longest streak of 1s (should never remove dups marked 0 as it will decrease score)
    int max_streak = 0, curr_streak = 0;
    int l = 0, r = 0, curr_l = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 1) {
            curr_streak++;
            if (max_streak <= curr_streak) {
                l = curr_l, r = i;
                max_streak = curr_streak;
            }
        } else {
            curr_streak = 0;
            curr_l = i + 1;
        }
    }

    if (max_streak == 0) {
        cout << 0 << "\n";
    } else {
        cout << l + 1 << " " << r + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
}