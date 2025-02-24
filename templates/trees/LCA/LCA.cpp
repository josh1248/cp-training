#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
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
  vvi graph(7);
  graph[0].emplace_back(2);
  graph[0].emplace_back(6);
  graph[2].emplace_back(3);
  graph[2].emplace_back(5);
  graph[3].emplace_back(1);
  graph[3].emplace_back(4);

  LCA res(graph);
  cout << "LCA of 1 and 6 is " << res.query(1, 6) << "\n";
  cout << "LCA of 2 and 5 is " << res.query(2, 5) << "\n";

  return 0;
}