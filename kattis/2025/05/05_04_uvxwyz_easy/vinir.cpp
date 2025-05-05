#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)


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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, Q; cin >> V >> Q;
    UnionFind uf(V);
    rep(i, 0, Q) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            --u, --v;
            uf.unionSet(u, v);
        } else {
            int w; cin >> w;
            --w;
            cout << uf.sizeOfSet(w) - 1 << "\n";
        }
    }
}