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
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;


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

    PURQ(const vi &f) { build(f); }        // create FT based on f

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

    int select(ll k) {                             // O(log m)
        int p = 1;
        while (p*2 < (int)ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i+p]) {
                k -= ft[i+p];
                i += p;
            }
            p /= 2;
        }
        return i+1;
    }

    void build(const vi &f) {
        int m = (int)f.size()-1;                     // note f[0] is always 0
        ft.assign(m+1, 0);
        for (int i = 1; i <= m; ++i) {               // O(m)
            ft[i] += f[i];                             // add this value
            if (i+LSOne(i) <= m)                       // i has parent
                ft[i+LSOne(i)] += ft[i];                 // add to that parent
        }
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

class RURQ {
private:
    RUPQ base;
    PURQ correction;
public:
    RURQ(int n): base(n), correction(n) {}

    void update(int i, int j, int v) {
        base.update(i, j, v);
        correction.update(i, (i - 1) * -v);
        correction.update(j + 1, j * v);
    }

    int rsq(int i) {
        return base.rsq(i) * i + correction.rsq(1, i);
    }

    int rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    RURQ ft(100);
    ft.update(1, 20, 5);
    ft.update(4, 40, 3);
    ft.update(60, 60, 100);

    for (int i = 1; i <= 100; i++) {
        cout << ft.rsq(i) << "\n";
    }

    cout << ft.rsq(31, 64) << "\n";
}