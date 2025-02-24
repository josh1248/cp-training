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

    string prev, s;
    vector<bool> OK(3);
    int N; cin >> N;
    auto move_lateral_ok = [&](int i, int j) {
        return ((s[i] == s[j]) && (s[i] == '.' || s[i] == '*'));
    };

    cin >> prev;
    OK[0] = (prev[0] == '.'), OK[1] = (prev[1] == '.'), OK[2] = (prev[2] == '.');

    rep(i, 1, N) {
        cin >> s;
        vector<bool> curr(3, false);
        // previous layer movement
        rep(j, 0, 3) {
            if (s[j] == '.' || s[j] == '/') {
                if (OK[j]) curr[j] = true;
            } else {
                if (OK[j] && (prev[j] == '/' || prev[j] == '*')) curr[j] = true;
            }
        }

        // lateral movement
        rep(j, 0, 2) {
            if (curr[0]) {
                curr[1] = curr[1] || move_lateral_ok(0, 1);
            }
            if (curr[1]) {
                curr[0] = curr[0] || move_lateral_ok(1, 0);
                curr[2] = curr[2] || move_lateral_ok(1, 2);
            }
            if (curr[2]) {
                curr[1] = curr[1] || move_lateral_ok(2, 1);
            }
        }

        // cout << i << ": ";
        // for(bool b: curr) {
        //     cout << b << " ";
        // } cout << "\n";

        if (!(curr[0] || curr[1] || curr[2])) {
            cout << "NO\n";
            return 0;
        }
        prev = s;
        OK = curr;
    }
    cout << ((OK[0] || OK[1] || OK[2]) ? "YES\n" : "NO\n");
    return 0;
}