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

    int V, E;
    
    // https://cp-algorithms.com/graph/bridge-searching.html
    bool bridgefound = false;
    vvi graph;
    vi lo, visittime;
    int timer;
    function<void(int, int)> dfs = [&](int u, int p) {
        lo[u] = visittime[u] = timer;
        timer++;
        for (int v: graph[u]) {
            if (p == v) continue;
            // neighbour has been visited and can visit you
            if (visittime[v] != -1) {
                lo[u] = min(lo[u], visittime[v]);
            } else {
                dfs(v, u);
                lo[u] = min(lo[u], lo[v]);
                // no one else has visited the neighbour
                // so removing u-v will prevent v from being visited.
                if (lo[v] > visittime[u]) {
                    bridgefound = true;
                }
            }
        }
    };

    while (cin >> V >> E) {
        if (V == 0) return 0;
        graph = vvi(V);
        lo = vi(V, -1), visittime = vi(V, -1);
        timer = 0;
        bridgefound = false;
        rep(i, 0, E) {
            int u, v; cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        rep(i, 0, V) {
            if (visittime[i] == -1) dfs(i, -1);
        }
        cout << (bridgefound ? "Yes" : "No") << "\n";

    }
}