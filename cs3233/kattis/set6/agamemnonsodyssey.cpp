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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int N, k; cin >> N >> k;
    vector<vector<pi>> graph(N + 1);
    ll total = 0;
    rep(i, 0, N - 1) {
        int u, v, c; cin >> u >> v >> c;
        graph[u].emplace_back(v, c);
        graph[v].emplace_back(u, c);
        total += c;
    }

    if (k > 1) {
        // can always take everything in a branch and come back (euler tour)
        cout << total << "\n";
        return 0;
    }

    
    ll best_seen = 0;
    // returns the most valuable branch starting from that node excluding the parent
    function<ll(int, int)> dfs = [&](int v, int parent) {
        ll max1 = 0, max2 = 0;
        for (auto& [nxt, weight]: graph[v]) {
            if (nxt == parent) continue;
            ll x = weight + dfs(nxt, v);
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
        }
        best_seen = max(best_seen, max1 + max2);
        return max1;
    };

    dfs(1, -1);
    cout << best_seen << "\n";
}