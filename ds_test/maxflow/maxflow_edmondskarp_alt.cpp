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
    ll mf_value;
    vector<unordered_map<int, ll>> AL;
    vi path; // holds ancestor used to reach node, or -1 if not traversed

    MF(int nodes): mf_value(0), AL(nodes) {}

    void add_edge(int u, int v, ll w) {
        AL[u][v] = w;
        AL[v][u] = 0;
    }

    void bfs(int s, int t) {
        path.assign(sz(AL), -1);
        queue<int> q;
        q.push(s);
        while (sz(q)) {
            int u = q.front(); q.pop();
            if (u == t) { return; }
            for (auto& [v, w]: AL[u]) {
                if ((path[v] != -1) || (v == s) || (w == 0)) continue;
                q.push(v);
                path[v] = u;
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
            int curr = t; // hold edge idx from u to v
            while (curr != s) {
                int up = path[curr];
                ll& w = AL[up][curr];
                min_w = min(min_w, w);
                curr = up;
            }

            res += min_w;
            
            curr = t;
            while (curr != s) {
                int up = path[curr];
                AL[up][curr] -= min_w; 
                AL[curr][up] += min_w; // leave backflow for "undo"
                curr = up;
            }

            // cout << "Flow gen: " << min_w << "\n";
            // cout << "Paths: ";
            // for (int i: path) {
            //     cout << i << " ";
            // }          
            // cout << "\n";
            // cout << "Edges:\n";
            // for (int i = 0; i < sz(AL); i++) {
            //     for (auto& [j, w]: AL[i]) {
            //         cout << i << " " << j << " " << w << "\n";
            //     }
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