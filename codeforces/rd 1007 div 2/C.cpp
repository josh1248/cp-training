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

vvi graph, depth_graph;
vector<bool> visited;
int max_depth;

void dfs(int v, int depth) {
    depth_graph[depth].emplace_back(v);
    max_depth = max(max_depth, depth);
    for (int& nxt: graph[v]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt, depth + 1);
    }
}

void solve() {
    int n, start, end; cin >> n >> start >> end;
    max_depth = 0;
    graph.clear(), depth_graph.clear(), visited.clear();
    graph.assign(n + 1, vi()), depth_graph.assign(n + 1, vi());
    visited.assign(n + 1, false);

    // invariant: if mouse is <= depth, mouse remains <= depth if we put cheese
    // at node at depth from end node
    // if mouse > depth, depth decreases by 1
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    visited[end] = true;
    dfs(end, 0);

    for (int i = max_depth; i >= 0; i--) {
        for (int& v: depth_graph[i]) {
            cout << v << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}