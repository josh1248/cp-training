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

    int n, q; cin >> n >> q;
    vi last_updated(n, -2), number_set(n);
    int most_recent_reset = -1;
    int base_val = 0;
    rep(turn_number, 0, q) {
        string cmd;
        cin >> cmd;
        if (cmd == "RESTART") {
            most_recent_reset = turn_number;
            cin >> base_val;
        } else if (cmd == "SET") {
            int i, x; cin >> i >> x;
            --i;
            last_updated[i] = turn_number;
            number_set[i] = x;
        } else {
            int check; cin >> check;
            --check;
            if (last_updated[check] < most_recent_reset) {
                cout << base_val << "\n";
            } else {
                cout << number_set[check] << "\n";
            }
        }
    }
}