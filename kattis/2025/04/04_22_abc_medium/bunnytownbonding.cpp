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

    string s; cin >> s;
    int cnt = 0;
    for (char c: s) {
        if (c == 'B') {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int best = 1e9;
    rep(i, 0, sz(s) + 1 - cnt) {
        int curr_hit = i;
        int acc = 0;
        rep(j, 0, sz(s)) {
            if (s[j] == 'B') acc += abs(j - curr_hit++);
        }
        best = min(best, acc);
    }
    cout << best << "\n";
}