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

    int t; string s; cin >> t >> s;
    int best_total = -1, best_a = -1, best_b = -1, idx = -1;
    rep(i, 0, t) {
        int a, b; cin >> a >> b;
        if (best_total < a + b) {
            best_total = a + b;
            best_a = a, best_b = b;
            idx = i + 1;
        } else if (best_total == a + b) {
            if (s == "antal" && a > best_a) {
                best_a = a, best_b = b;
                idx = i + 1;
            } else if (s == "storlek" && b > best_b) {
                best_a = a, best_b = b;
                idx = i + 1;
            }
        }
    }
    cout << idx << "\n";
}