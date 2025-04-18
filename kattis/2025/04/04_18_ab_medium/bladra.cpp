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

    int k, q; cin >> k >> q;
    vi cnts(k, 0);
    rep(i, 0, q) {
        int x, y; cin >> x >> y;
        cnts[y-1]++;
    }
    int lowest = q + 1;
    rep(i, 0, k) {
        lowest = min(lowest, cnts[i]);
    }
    cout << lowest << "\n";
}