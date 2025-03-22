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

vvi curr_grid;
const int EMPTY = 0, BUILDING = 1, FLOODED = 2;

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
    int R, C; cin >> R >> C;
    vvi grid_original = vvi(R, vi(C, EMPTY));
    vvi flood_map = vvi(R, vi(C, -1));
    vector<tuple<int, int, int, int>> boxes(R * C);
    rep(i, 0, R) {
        rep(j, 0, C) {
            char c; cin >> c;
            if (c == '1') {
                grid_original[i][j] = BUILDING;
                boxes[i * C + j] = {i, i, j, j};
            }
        }
    }


    UnionFind uf(R * C);
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (grid_original[i][j] != EMPTY) continue;
            rep(k, 0, 4) {
                int newr = i + dr[k], newc = j + dc[k];
                if (newr < 0 || newr >= R || newc < 0 || newc >= C) continue;
                if (grid_original[newr][newc] == EMPTY) {
                    uf.unionSet(i * C + j, newr * C + newc);
                    auto [o1, o2, o3, o4] = boxes[i * C + j];
                    auto [n1, n2, n3, n4] = boxes[newr * C + newc];
                    boxes[i * C + j] = tuple<int, int, int, int>(min(o1, n1), max(o2, n2), min(o3, n3), max(o4, n4));
                    boxes[newr * C + newc] = tuple<int, int, int, int>(min(o1, n1), max(o2, n2), min(o3, n3), max(o4, n4));
                }              
            }
        }
    }

    unordered_set<int> reps;
    rep(i, 0, R) {
        rep(j, 0, C) {
            int rep = uf.findSet(i * C + j);
            if (grid_original[i][j] == EMPTY && reps.count(rep) == 0) {
                reps.insert(rep);
            }
        }
    }

    // order reps by row
    //

    // now, run DFS per rep
    for (int rep: reps) {
        // merge with all representatives inside box
        // 2D interval check
    }
    cout << acc << "\n";
}