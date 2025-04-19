#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

class UnionFind {
private:
    vi parent;
    vi weight;
    int numSets;
public:
    UnionFind(int N): parent(N), weight(N), numSets(N) {
        rep(i, 0, N) parent[i] = i;
        rep(i, 0, N) weight[i] = 1;
    }

    int find(int idx) {
        if (parent[idx] == idx) return idx;
        while (parent[idx] != find(parent[idx])) {
            parent[idx] = find(parent[idx]);
        }
        return parent[idx];
    }

    void joinSets(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (weight[px] > weight[py]) swap(px, py);
        parent[px] = py;
        weight[py] += weight[px];
        numSets--;
    }

    vi getSetSizes() {
        vi ans;
        rep(i, 0, sz(parent)) {
            if (parent[i] == i) ans.push_back(weight[i]);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E; cin >> V >> E;

    UnionFind uf(V);
    rep(i, 0, E) {
        int u, v; cin >> u >> v;
        --u, --v;
        uf.joinSets(u, v);
    }
    vi sizes = uf.getSetSizes();
    int m = -1;
    for (int i: sizes) m = max(m, i);
    cout << m << "\n";
    return 0;
}