#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  vi ors;
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
    ors.assign(N, 0);
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j, int orval) {
    int x = findSet(i), y = findSet(j);          // find both rep items
    ors[x] |= orval;
    ors[y] |= orval;
    ors[x] |= ors[y];
    ors[y] |= ors[x];
    if (isSameSet(i, j)) return;  // i and j are in same set
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        ll u, v, val; cin >> u >> v >> val;
        uf.unionSet(u, v, val);
    }
    for (int i = 0; i < q; i++) {
        ll u, v; cin >> u >> v;
        if (!uf.isSameSet(u, v)) {
            cout << -1 << "\n";
        } else {
            cout << __builtin_popcount(uf.ors[uf.findSet(u)]) << "\n";
        }
    }
}