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

    int n; cin >> n; ll max_cap = 0, curr_cap = 0;
    rep(i, 0, n) {
        ll leave, board; cin >> leave >> board;
        curr_cap -= leave;
        curr_cap += board;
        max_cap = max(max_cap, curr_cap);
    }
    cout << max_cap << "\n";
}