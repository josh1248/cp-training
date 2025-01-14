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

class ST {
private:
    vi nodes, leaves, lazy;
    int leftchild(int pos) { return 2 * pos + 1; }
    int rightchild(int pos) { return 2 * pos + 2; }

    // determines what property to keep from children nodes
    int conquer(int i, int j) {
        return min(i, j);
    }

    // l and r denote the subarray of nodes[pos]
    void update(int i, int l, int r, int pos, int v) {
        if (i < l || i > r || l > r) {
            return;
        } else if (l == r) {
            nodes[pos] = v;
            leaves[pos] = v;
            return;
        }
        int m = (l + r) / 2;
        update(i, l, m, leftchild(pos), v);
        update(i, m + 1, r, rightchild(pos), v);
        nodes[pos] = conquer(nodes[leftchild(pos)], nodes[rightchild(pos)]);
    }

    // keep cutting until subarray interval is within query bounds
    int query(int pos, int l, int r, int l_bound, int r_bound) {
        if (l_bound <= l && r <= r_bound) {
            return nodes[pos];
        }

        int m = (l + r) / 2;
        if (m >= r_bound) {
            return query(leftchild(pos), l, m, l_bound, r_bound);
        } else if (m < l_bound) {
            return query(rightchild(pos), m + 1, r, l_bound, r_bound);
        } else {
            return conquer(
                query(leftchild(pos), l, m, l_bound, r_bound),
                query(rightchild(pos), m + 1, r, l_bound, r_bound)
            );
        }
    }

    void build(int pos, int l, int r) {     
        if (l == r) {
            nodes[pos] = leaves[l];
        } else {
            int m = (l + r) / 2;
            build(leftchild(pos), l, m);
            build(rightchild(pos), m + 1, r);
            nodes[pos] = conquer(nodes[leftchild(pos)], nodes[rightchild(pos)]); 
        }
    }

public:
    ST(int n): nodes(4 * n, 0), leaves(n, 0), lazy(4 * n, 0) {}

    ST(vi& v): nodes(4 * v.size()), leaves(v), lazy(4 * v.size(), 0) {
        build(0, 0, v.size() - 1);
    }

    void update(int i, int v) {
        update(i, 0, leaves.size() - 1, 0, v);
    }

    int query(int i, int j) {
        return query(0, 0, leaves.size() - 1, i, j);
    }

    void print() {
        cout << "Leaves: ";
        for (int i: leaves) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "Nodes: ";
        for (int i: nodes) {
            cout << i << " ";
        }
        cout << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi base = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    ST test(base);

    cout << test.query(1, 7) << "\n";
}