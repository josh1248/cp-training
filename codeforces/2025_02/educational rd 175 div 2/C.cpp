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
    int n, k; string s;
    cin >> n >> k >> s;
    vi data(n);
    rep(i, 0, n) {
        cin >> data[i];
    }

    // first, check if it can be always fulfilled
    int contiguous_b = 0;
    bool state = false;
    for (char c: s) {
        if (c == 'R') {
            state = false;
        } else if (c == 'B' && !state) {
            state = true;
            contiguous_b++;
        }
    }
    if (contiguous_b <= k) {
        cout << 0 << "\n";
        return;
    }

    // not possible. binary search.
    vi sorted_data(data);
    sort(all(sorted_data));
    int l = 0, r = sz(sorted_data) - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int penalty_cap = sorted_data[mid];
        // cout << l << " " << r << " " << sorted_data[mid] << "\n";
        // fulfill only those > penalty.
        int contiguous_blues = 0;
        bool blue_now = false;
        rep(i, 0, sz(data)) {
            if (data[i] <= penalty_cap) continue;
            char c = s[i];
            if (c == 'R') {
                blue_now = false;
            } else if (c == 'B' && !blue_now) {
                blue_now = true;
                contiguous_blues++;
            }
        }
        if (contiguous_blues <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << sorted_data[l] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}