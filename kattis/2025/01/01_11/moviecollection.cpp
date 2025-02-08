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

// base Fenwick Tree (1-indexed)
class PURQ {
private:
    vi ft;

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

void solve() {
    int n, q; cin >> n >> q;
    RUPQ ft(n + q);
    vi pos(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pos[n - i + 1] = i;
        ft.update(i, i, n - i);
    }

    for (int i = 0; i < q; i++) {
        int movie; cin >> movie;
        cout << ft.rsq(pos[movie]) << " ";
        ft.update(1, pos[movie], -1);
        ft.update(1, n + i, 1);
        pos[movie] = n + i + 1;
    }
    cout << "\n";
}

/*
Set initial array as n ... 2 1
define ft[i] as the relative position of the movie at i
for each movie, keep track of the last index it is in

for some query of movie x, find last position of x.
append x to the array
update ft[1...pos[x]]--
update ft[1...arr.size() - 1]++
update pos[x] as arr.size()
net result: only the movies after pos[x] have an extra movie on top of it
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}