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

    int C, R; cin >> C >> R;
    vi awarded(C);
    vector<string> sols(C);
    rep(i, 0, C) cin >> sols[i];
    rep(i, 0, R) {
        rep(j, 0, C) {
            int x; cin >> x;
            awarded[j] += x;
        }
    }
    int m = 0, idx = -1;
    rep(i, 0, C) {
        if (awarded[i] > m) {
            m = awarded[i];
            idx = i;
        }
    }
    cout << sols[idx] << "\n";
}