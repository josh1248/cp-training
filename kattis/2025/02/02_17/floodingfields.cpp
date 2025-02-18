#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc; // capacity, original capacity
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};

	vi lvl; // level graph (depths at each node)
    vi ptr; // current arc of each node (minimal target vertex where flows still possible)
    vi q; // BFS cumulative queue
	vector<vector<Edge>> adj; // adjacency list
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
        // L is the scaling factor in Dinic's
        // consider and allocate large flows before considering small flows
        // reduce time taken to O(V^2 sqrt(E))
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1; // start and end pointer of queue
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
    // final level graph (which will consist of all vertices)
    // level allocation != 0 -> traversed, lies within S cut
    // level allocation == 0 -> not traversed, within T cut
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, k, h; cin >> n >> k >> h;
    vvi levels(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> levels[i][j];
        }
    }
    // vertex number: n^2*h + n*r + c + 1
    // last 2 vertices: super source, super sink
    // one extra layer for hour 0, one extra layer to flow to hour n + 1
    int vertices = n * n * (h + 2) + 2;
    vector<vector<int>> graph(vertices);
    int S = vertices - 2, T = vertices - 1;

    for (int i = 0; i < k; i++) {
        // flow cows into hour 0 grid
        int r, c; cin >> r >> c;
        graph[S].push_back(r * n + c);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[n * n * (h + 1) + n * i + j].push_back(T);
        }
    }

    int dr[5] = {0, 1, -1, 0, 0};
    int dc[5] = {0, 0, 0, 1, -1};

    vi flood_levels(h + 1);
    for (int i = 0; i < h; i++) {
        cin >> flood_levels[i + 1];
    }
    flood_levels[0] = -1;

    int v = 0;
    for (int curr_h = 0; curr_h <= h; curr_h++) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (levels[r][c] > flood_levels[curr_h]) {
                    for (int i = 0; i < 5; i++) {
                        int new_r = r + dr[i], new_c = c + dc[i];
                        if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n) {
                            continue;
                        }
                        graph[v].push_back(n * n * (curr_h + 1) + n * new_r + new_c);
                    }
                }
                v++;
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j: graph[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }

    Dinic mf(vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j: graph[i]) {
            mf.addEdge(i, j, 1, 0);
        }
    }

    cout << mf.calc(S, T) << "\n";
}