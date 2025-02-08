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
typedef pair<int, int> pi;
typedef long long ll;

class UnionFind {
public:
    vi v, rank, setSize;
    UnionFind(int size) {
        v = vi(size, 0);
        rank = vi(size, 0);
        setSize = vi(size, 1);
        for (int i = 0; i < size; i++) {
            v[i] = i;
        }
    }

    int find(int idx) {
        while (v[idx] != idx) {
            v[idx] = find(v[idx]);
            idx = v[idx];
        }
        return idx;
    }

    void u(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) {
            return;
        }

        if (rank[px] < rank[py]) {
            swap(px, py);
        }

        v[py] = px;
        rank[px]++;
        setSize[px] += setSize[py];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    UnionFind uf(500'001); int res = 0;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        map<int, int> used_caulds;
        for (int j = 0; j < m; j++) {
            int p; cin >> p;
            int p_parent = uf.find(p);
            if (used_caulds.count(p_parent) == 0) {
                used_caulds[p_parent] = 0;
            }
            used_caulds[p_parent]++;
        }

        auto pred = [&uf](const pi& p){
            return uf.setSize[p.first] == p.second; 
        };

        if (!all_of(used_caulds.begin(), used_caulds.end(), pred)) {
            continue;
        }

        res++;
        int parent = used_caulds.begin()->first;
        for (auto [k, _]: used_caulds) {
            uf.u(parent, k);
        }
    }

    cout << res << "\n";
}