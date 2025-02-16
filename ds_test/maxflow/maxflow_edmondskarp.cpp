#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

struct edge {
    int u, v; ll w;
    edge(int u, int v, ll w): u(u), v(v), w(w) {}
};

struct MF {
    vvi AL; // hold edge number as neighbour
    vector<edge> EL;
    vi path; // holds ancestor used to reach node, or -1 if not traversed

    MF(int nodes): AL(nodes) {}

    void add_edge(int u, int v, ll w) {
        EL.emplace_back(u, v, w);
        AL[u].push_back(sz(EL) - 1);
        // back edges
        EL.emplace_back(v, u, 0);
        AL[v].push_back(sz(EL) - 1);
    }

    void bfs(int s, int t) {
        path.assign(sz(AL), -1);
        queue<int> q;
        q.push(s);
        while (sz(q)) {
            int u = q.front(); q.pop();
            if (u == t) { return; }
            for (auto& e: AL[u]) {
                auto& [_, v, w] = EL[e];
                if ((path[v] != -1) || (v == s) || (w == 0)) continue;
                q.push(v);
                path[v] = e;
            }
        }
    }

    ll maxflow_edmondskarp(int s, int t) {
        ll res = 0;
        // while augmenting path
        while (true) {
            bfs(s, t);
            if (path[t] == -1) break;

            ll min_w = 1e18;
            int curr = path[t]; // hold edge idx from u to v
            while (curr != -1) {
                auto& [u, v, w] = EL[curr];
                min_w = min(min_w, w);
                curr = path[u];
            }

            res += min_w;
            
            curr = path[t];
            while (curr != -1) {
                auto& [u, v, w] = EL[curr];
                EL[curr + (curr % 2 == 0 ? 1 : -1)].w += min_w; // leave backflow for "undo"
                EL[curr].w -= min_w;
                curr = path[u];
            }

            // cout << "Flow gen: " << min_w << "\n";
            // cout << "Paths: ";
            // for (int i: path) {
            //     cout << i << " ";
            // }          
            // cout << "\n";
            // cout << "Edges:\n";
            // int i = 0;
            // for (auto& [u, v, w]: EL) {
            //     cout << i << ": ";
            //     cout << u << "|" << v << "|" << w << "\n";
            //     i++;
            // }
        }
        return res;
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m, s, t; cin >> n >> m >> s >> t;
    MF mf(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mf.add_edge(u, v, w);
    }

    cout << mf.maxflow_edmondskarp(s, t) << "\n";
}