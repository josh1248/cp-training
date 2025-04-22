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
    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        int lo = -1, hi = -1;
        int state = 0; // 0: find 1, 1: find 0, 2: find another 1 if possible, 3: done
        rep(i, 0, n) {
            if (state == 0 && s[i] == '1') {
                state++;
                lo = i;
            }
            if (state == 1 && s[i] == '0') {
                state++;
            }
            if (state == 2) {
                if (s[i] == '1') {
                    hi = i - 1;
                    state++;
                } else if (i == n - 1) {
                    hi = i;
                    state++;
                }
            }
        }
        if (state == 3) {
            reverse(begin(s) + lo, begin(s) + hi + 1);
        }
        // cout << state << " " << s << " " << lo << " " << hi << " ";
        ll ops = 0;
        bool curr = false;
        for (char c: s) {
            if (c == '0' && !curr) ops++;
            else if (c == '1' && curr) ops++;
            else {
                ops += 2;
                curr = !curr;
            }
        }
        cout << ops << "\n";
    }
}