#include <bits/stdc++.h>
/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc; // capacity, original capacity
		ll flow() { return max(oc - c, 0LL); } // if you need flows (extract through AL)
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E, S, T; cin >> V >> E >> S >> T;
    Dinic mf(V + 1); // 1-indexed graph input (change for 0-indexed)
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // undirected - indicate reverse flow in that case
		mf.addEdge(u, v, w, w); 
    }
}