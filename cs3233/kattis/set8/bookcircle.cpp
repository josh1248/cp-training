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

/*
This is a bipartite MVC problem
Edges represent the books, left vertices are boys, right vertices are girls
We want to minimize the vertices used s.t. for every edge (i.e. book), must select
either vertex.
By Konig's theorem, |MCBM| = |MVC|.
*/
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
    int idx = 0;
    map<string, int> book_mapping;
    map<int, int> boys, girls; // book index -> person who read it
    int B, G; cin >> B >> G;
    Dinic mf(B + G + 2);
    int source = B + G, sink = B + G + 1;
    rep(i, 0, B) {
        mf.addEdge(source, i, 1);
        string s; int n; cin >> s >> n;
        rep(j, 0, n) {
            cin >> s;
            if (book_mapping.count(s) == 0) {
                book_mapping[s] = idx++;
            }
            boys[book_mapping[s]] = i; 
        }
    }
    rep(i, 0, G) {
        mf.addEdge(i + B, sink, 1);
        string s; int n; cin >> s >> n;
        rep(j, 0, n) {
            cin >> s;
            if (book_mapping.count(s) == 0) {
                book_mapping[s] = idx++;
            }
            girls[book_mapping[s]] = i; 
        }
    }
    rep(i, 0, idx) {
        int u = boys[i], v = B + girls[i];
        mf.addEdge(u, v, 1);
    }
    cout << mf.calc(source, sink) << "\n";
    // for (int i = 0; i < B + G + 2; i++) {
    //     for (auto& e: mf.adj[i]) {
    //         if (e.flow() > 0)  {
    //             cout << i << " " << e.to << "\n";
    //         }
    //     }
    // }
    return 0;
}