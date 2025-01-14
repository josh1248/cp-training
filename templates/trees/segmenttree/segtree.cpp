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
    vi nodes, leaves;
    int leftchild(int pos) { return 2 * pos + 1; }
    int rightchild(int pos) { return 2 * pos + 2; }

    void update(int i, int l, int r, int pos, int v) {
        if (i < l || i > r || l > r) {
            return;
        }

        nodes[pos] += v;
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        update(i, l, m, leftchild(pos), v);
        update(i, m + 1, r, rightchild(pos), v);
    }

    int build(int l, int r, int pos) {

    }
public:
    ST(int n): nodes(4 * n), leaves(n) {}

    ST(vi& v): nodes(4 * v.size()), leaves(v) {

    }

    void update(int i, int v) {
        update(i, 0, nodes.size(), 0, v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   
}