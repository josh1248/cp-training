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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vi v;
    int x;
    rep(i, 0, m) {
        cin >> x;
        // not interesting to us
        if (x == n) {
            continue;
        } else {
            // placing non-rainbow intervals
            v.push_back(n - x);
        }
    }
    sort(all(v));

    if (int(v.size()) == 0) {
        cout << 1 << "\n";
    } else {
        // find number of non-overlapping non-rainbow intervals we can build
        // answer is proxy to actual rainbow intervals
        int remaining = n - v[v.size() - 1] - 1;
        int best = 1;
        rep(i, 0, int(v.size()) - 1) {
            remaining -= (v[i] + 1);
            if (remaining < 0) {
                break;
            } else {
                best++;
            }
        }
        cout << best << "\n";
    }
}