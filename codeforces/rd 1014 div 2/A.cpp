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
    int N; cin >> N;
    vi sheep(N);
    rep(i, 0, N) cin >> sheep[i];
    int record = -1;
    rep(x, 0, N) {
        rep(y, x + 1, N) {
            int a = sheep[x], b = sheep[y];
            if (a > b) swap(a, b);
            int diff = b - a;
            record = max(record, diff);
        }
    }
    cout << record << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}