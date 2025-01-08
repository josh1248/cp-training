#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

class UnionFind {
public:
    vi uf; vi sizes;

    UnionFind(int n) {
        uf = vi(n);
        sizes = vi(n);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int x) {
        if (uf[x] != x) {
            uf[x] = find(uf[x]);
        }
        return uf[x];
    }

    void u(int x, int y) {
        int xs = find(x); int ys = find(y);
        if (xs == ys) {
            return;
        } else if (sizes[xs] <= sizes[ys]) {
            uf[xs] = ys;
            sizes[ys] += sizes[xs];
        } else {
            uf[ys] = xs;
            sizes[xs] += sizes[ys];
        }
    } 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x, y; char op;
    cin >> n >> q;
    UnionFind uf(n);

    for (int i = 0; i < q; i++) {
        cin >> op >> x >> y;
        if (op == '?') {
            if (uf.find(x) == uf.find(y)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else {
            uf.u(x, y);
        }
    }
}