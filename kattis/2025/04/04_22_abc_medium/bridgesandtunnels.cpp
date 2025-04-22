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
public:
    vi setSize, parent;
    UnionFind(int V): setSize(V), parent(V) {
        rep(i, 0, V) setSize[i] = 1;
        rep(i, 0, V) parent[i] = i;
    }

    int find(int x) {
        while (parent[x] != parent[parent[x]]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void combine(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (setSize[px] > setSize[py]) swap(px, py);
        parent[px] = py;
        setSize[py] += setSize[px];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int B; cin >> B;
    unordered_map<string, int> mapping;
    int highest_idx = 0;
    UnionFind uf(2 * B);
    rep(i, 0, B) {
        string x, y; cin >> x >> y;
        if (mapping.count(x) == 0) mapping[x] = highest_idx++;
        if (mapping.count(y) == 0) mapping[y] = highest_idx++;
        int u = mapping[x], v = mapping[y];
        uf.combine(u, v);
        cout << uf.setSize[uf.find(u)] << "\n";
    }
}
