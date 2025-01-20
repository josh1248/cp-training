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


// UFDS graph G to find connected components
// in graph F, remove connection between vertices if they belong to different connected components in G
// afterwards, join connected components in G based on no. of(F components) - no. of(G components)
void solve() {
    int v, m1, m2; cin >> v >> m1 >> m2;
    vector<set<int>> graphF(v + 1), graphG(v + 1);
    UnionFind ufF(v + 1), ufG(v + 1);

    for (int i = 0; i < m1; i++) {
        int x, y; cin >> x >> y;
        graphF[x].insert(y);
        graphF[y].insert(x);
    }

    for (int i = 0; i < m2; i++) {
        int x, y; cin >> x >> y;
        graphG[x].insert(y);
        graphG[y].insert(x);
        ufG.unionSet(x, y);
    }

    // destroy
    int res = 0;
    for (int i = 1; i <= v; i++) {
        vi removals;
        for (int j: graphF[i]) {
            if (!ufG.isSameSet(i, j)) {
                res++;
                graphF[j].erase(i);
                removals.push_back(j);
            }
        }
        for (int j: removals) {
            graphF[i].erase(j);
        }
    }

    // Find connected components
    for (int i = 1; i <= v; i++) {
        for (int j: graphF[i]) {
            ufF.unionSet(i, j);
        }
    }

    cout << res + ufF.numDisjointSets() - ufG.numDisjointSets() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}