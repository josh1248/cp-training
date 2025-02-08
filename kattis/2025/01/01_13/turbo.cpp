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

// adapted from https://github.com/stevenhalim/cpbook-code/blob/master/ch2/ourown/fenwicktree_ds.cpp

// base Fenwick Tree
class PURQ {
private:
    vi ft; // dynamic freq table

    int LSOne(int s) {
        return ((s) & (-s));
    }
public:
    PURQ(int N) {
        ft.assign(N + 1, 0);
    }

    void update(int i, int v) {
        while (i < ft.size()) {
            ft[i] += v;
            i += LSOne(i);
        }
    }

    // [1...i]
    int rsq(int i) {
        int res = 0;
        while (i > 0) {
            res += ft[i];
            i -= LSOne(i);
        }
        return res;
    }

    int rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }
};

class RUPQ {
private:
    PURQ ft;
public:
    RUPQ(int n) : ft(n) {}

    void update(int i, int j, int v) {
        ft.update(i, v);
        ft.update(j + 1, -v);
    }

    int rsq(int i) {
        return ft.rsq(i);
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n; cin >> n;
    PURQ used(n); // to calculate "used numbers"
    vi pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        pos[k] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            int target = (i + 1) / 2;
            int p = pos[target];
            int adjusted = p - used.rsq(1, p);
            cout << adjusted - 1 << "\n";
            used.update(p, 1);
        } else {
            int target = n - (i / 2) + 1;
            int p = pos[target];
            int adjusted = p - used.rsq(1, p);
            // only n - i + 1 remaining elements
            cout << (n - i + 1) - adjusted << "\n";
            used.update(p, 1);
        }
    }
    return 0;
}