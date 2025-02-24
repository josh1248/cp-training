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

    map<pi, int> cnts;
    ll N, M; cin >> N >> M;
    ll u, v;
    rep(i, 0, M) {
        cin >> u >> v;
        if (cnts.count({u, v}) == 0) {
            cnts[{u, v}] = 0;
        }
        cnts[{u, v}]++;
    }

    int W; cin >> W;

    ll prev, curr; cin >> prev;
    rep(i, 0, W) {
        cin >> curr;
        if (curr < 1 || curr > N) {
            cout << i + 1 << "\n";
            return 0;
        }
        if (cnts.count({prev, curr}) == 0 || cnts[{prev, curr}] == 0) {
            cout << i + 1 << "\n";
            return 0;
        }
        cnts[{prev, curr}]--;
        prev = curr;
    }

    // cannot terminate early - may have invalid edge
    cout << (W == M ? "correct" : "too short") << "\n";
}