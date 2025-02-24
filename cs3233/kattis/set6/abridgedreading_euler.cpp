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

// adapted and courtesy of https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/segmenttree_ds.cpp
// plus https://cp-algorithms.com/graph/lca.html
struct LCA {
    int n;
    vvi graph;
    vector<pi> depths, st, tour;
    vi visits; // store first seen idx in tour
    const pi none = {int(1e9), int(1e9)};
  
    int l(int p) { return  p<<1; }                 // left child
    int r(int p) { return (p<<1)+1; }              // right child
  
    pi conquer(pi a, pi b) {
      return (a.first <= b.first ? a : b);         // RMQ
    }
  
    // modified DFS
    void euler(int v, int depth) {
        visits[v] = sz(tour);
        tour.emplace_back(depth, v);
        
        for (auto& nxt: graph[v]) {
            euler(nxt, depth + 1);
            tour.emplace_back(depth, v);
        }
    };
  
    void build(int p, int L, int R) {              // O(n)
      if (L == R)
        st[p] = tour[L];
      else {
        int m = (L+R)/2;
        build(l(p), L  , m);
        build(r(p), m+1, R);
        st[p] = conquer(st[l(p)], st[r(p)]);
      }
    }
  
    pi query(int p, int L, int R, int i, int j) {   // O(log n)
      if (i > j) return none;                        // infeasible
      if ((L >= i) && (R <= j)) return st[p];      // found the segment
      int m = (L+R)/2;
      return conquer(query(l(p), L  , m, i          , min(m, j)),
                     query(r(p), m+1, R, max(i, m+1), j        ));
    }
  
    // 0-rooted tree.
    LCA(const vvi &AL): n(sz(AL)), graph(AL), depths(n), st(8 * n, none), visits(n) {
      euler(0, 0);
      build(1, 0, 2 * n - 2);
    }
  
    // returns vertex number of LCA in original immutable graph.
    int query(int i, int j) {
        int vi = visits[i], vj = visits[j];
        if (vi > vj) swap(vi, vj);
        return query(1, 0, 2 * n - 2, vi, vj).second;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vvi graph(N + 1);
    vi weights(N + 1);
    vi parent(N + 1, 0);
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

    LCA res(graph);
    vll parentWeights(N + 1, 0);
    function<void(int, ll)> dfs = [&](int v, ll acc) {
        parentWeights[v] = acc;
        for (auto& nxt: graph[v]) {
            dfs(nxt, acc + weights[nxt]);
        }
    };
    dfs(0, 0ll);

    // consider all possible pairs, and cut the LCA weight off
    ll best_so_far = 4e18;
    rep(i, 1, N + 1) {
        rep(j, i + 1, N + 1) {
            if (sz(graph[i]) != 0 || sz(graph[j]) != 0) continue; // not leaf nodes
            int lca = res.query(i, j);
            best_so_far = min(best_so_far, parentWeights[i] + parentWeights[j] - parentWeights[lca]);
        }
    }
    cout << best_so_far << "\n";
    return 0;
}
