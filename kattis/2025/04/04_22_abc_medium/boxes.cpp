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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  int V; cin >> V;
  vvi graph(V + 1); // 0 is the supernode
  rep(i, 1, V + 1) {
    int parent; cin >> parent;
    graph[parent].push_back(i);
  }

  vi totalweight(V + 1, -1);
  function<int(int)> getweight = [&](int u) {
    if (sz(graph[u]) == 0) return totalweight[u] = 1;
    int acc = 1;
    for (int& v: graph[u]) acc += getweight(v);
    return totalweight[u] = acc;
  };
  rep(i, 0, V + 1) {
    if (totalweight[i] == -1) getweight(i);
  }

  LCA tour(graph);
  int q; cin >> q;
  rep(i, 0, q) {
    int t; cin >> t;
    vi uniqueparents(t);
    rep(j, 0, t) cin >> uniqueparents[j];
    vector<bool> ok(t, true);
    rep(j, 0, t) {
      rep(k, j + 1, t) {
        int a = min(uniqueparents[j], uniqueparents[k]),
            b = max(uniqueparents[j], uniqueparents[k]);
        int lca = tour.query(a, b);
        if (lca == uniqueparents[j]) ok[k] = false;
        if (lca == uniqueparents[k]) ok[j] = false; 
      }
    }
    int acc = 0;
    rep(j, 0, t) {
      if (ok[j]) acc += totalweight[uniqueparents[j]];
    }
    cout << acc << "\n";
  }
}