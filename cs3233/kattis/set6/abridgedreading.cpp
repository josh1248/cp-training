#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vvi graph(N + 1);
    vi weights(N + 1);
    vi parent(N + 1, 0); parent[0] = -1; // 0 is the super source
    vll res(N + 1, 1e9);
    rep (i, 0, N) {
        cin >> weights[i + 1];
    }
    rep (i, 0, M) {
        int u, v; cin >> u >> v;
        parent[v] = u;
        graph[u].emplace_back(v);
    }
    rep(i, 1, N + 1) {
        if (parent[i] == 0) {
            graph[0].emplace_back(i);
        }
    }

    ll best_so_far = 4e18;
    // return lowest path starting from this node
    function<ll(int, ll)> dfs = [&](int v, ll acc) {
        res[v] = acc;
        if (sz(graph[v]) == 0) {
            return acc;
        }

        ll smallest = 4e18, smallest2 = 4e18;
        for (auto& nxt: graph[v]) {
            ll x = dfs(nxt, acc + weights[nxt]);
            if (x < smallest) {
                smallest2 = smallest;
                smallest = x;
            } else if (x < smallest2) {
                smallest2 = x;
            }
        }

        // 2 or more leaves contained
        if (smallest2 != ll(4e18)) {
            best_so_far = min(best_so_far, smallest + smallest2 - acc);
        }
        return smallest;
    };

    dfs(0, 0ll);

    cout << best_so_far << "\n";
    return 0;
}
