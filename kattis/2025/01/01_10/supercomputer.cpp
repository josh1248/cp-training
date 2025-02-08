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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    PURQ ft(n + 1);
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        if (c == 'F') {
            int b; cin >> b;
            if (ft.rsq(b, b) == 0) {
                ft.update(b, 1);
            } else {
                ft.update(b, -1);
            }
        } else {
            int l, r; cin >> l >> r;
            cout << ft.rsq(l, r) << "\n";
        }
    }
}