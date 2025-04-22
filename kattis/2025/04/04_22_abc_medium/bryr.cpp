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
    vector<vector<pi>> graph(V);
    rep(i, 0, E) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vi estimates(V, 1e8);
    priority_queue<pi> pq;
    pq.emplace(0, 0);
    while (sz(pq) > 0) {
        auto [negw, u] = pq.top(); pq.pop();
        int w = -negw;
        if (estimates[u] < w) continue;
        for (auto& [v, nxtw]: graph[u]) {
            if (w + nxtw < estimates[v]) {
                estimates[v] = w + nxtw;
                pq.emplace(-(w + nxtw), v);
            }
        }
    }
    cout << estimates[V - 1] << "\n";
}