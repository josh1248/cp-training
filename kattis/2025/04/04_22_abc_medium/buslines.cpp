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

    int V, E; cin >> V >> E;
    // possible sums: 3 to 2n - 1 (2n - 3 total)
    if (E < V - 1 || E > 2 * V - 3) {
        cout << "-1\n";
        return 0;
    }
    // connect with 1-2, 1-3, ... 1-n
    // then n-2, n-3, ... to fulfil remaining edges
    rep(i, 0, V - 1) {
        cout << 1 << " " << i + 2 << "\n";
    }
    rep(i, 0, E - V + 1) {
        cout << i + 2 << " " << V << "\n";
    }
}