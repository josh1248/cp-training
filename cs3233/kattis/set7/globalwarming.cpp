// This code uses new C++17 structured binding
// use this compiler setting "g++ -O2 -std=gnu++17 {cpp17file}"

// Disclaimer: This code is a hybrid between old CP1-2-3 implementation of
// Edmonds Karp's algorithm -- re-written in OOP fashion and the fast
// Dinic's algorithm implementation by
// https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc
// This code is written in modern C++17 standard

// We replace BFS with SPFA

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll, ll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

const ll INF = 1e18; // INF = 1e18, not 2^63-1 to avoid overflow

class UnionFind {                                // OOP style
  private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
  public:
    UnionFind(int N) {
      p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
      rank.assign(N, 0);                           // optional speedup
      setSize.assign(N, 1);                        // optional feature
      numSets = N;                                 // optional feature
    }
  
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  
    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
  
    void unionSet(int i, int j) {
      if (isSameSet(i, j)) return;                 // i and j are in same set
      int x = findSet(i), y = findSet(j);          // find both rep items
      if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
      p[x] = y;                                    // set x under y
      if (rank[x] == rank[y]) ++rank[y];           // optional speedup
      setSize[y] += setSize[x];                    // combine set sizes at y
      --numSets;                                   // a union reduces numSets
    }
  };

vector<ll> dp;

// 23 choose 2 = 253 > 250
ll weightedMCM(int mask) {
  ll& ans = dp[mask];
  if (ans != -1) return ans;
  rep(i, 0, 23) {
    if (mask & ())
  }
  int last = __builtin_clz(mask);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M; cin >> N >> M;
  UnionFind uf(N);
  vector<tuple<int, int, ll>> EL;
  rep(i, 0, M) {
    int u, v, w; cin >> u >> v >> w;
  }

  rep(i, 1, N + 1) {
    mf.add_edge(source, i, 1, 0);
    mf.add_edge(i + N, sink, 1, 0);
    mf.add_edge(i + N, i, 1, 0);
  }
  for (int i = 0; i < M; ++i) {
    int u, v, c; cin >> u >> v >> c;
    mf.add_edge(u, v + N, 1, c);                      // default: directed edge
    mf.add_edge(v, u + N, 1, c);
  }
  pair<ll, ll> res = mf.mcmf(source, sink);
  auto& [maxflow, mincost] = res;
  if (maxflow != N) {
    cout << "impossible\n";
  } else {
    cout << mincost << "\n";
  }
  return 0;
}