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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<PURQ> ft(6, PURQ(n));
    int values[6];

    for (int i = 0; i < 6; i++) {
        int val; cin >> val;
        values[i] = val;
    }

    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ft[s[i] - '1'].update(i + 1, 1);
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int k, p; cin >> k >> p;
            int org = (s[k - 1] - '1');
            ft[org].update(k, -1);
            s[k - 1] = (p + '0');
            ft[p - 1].update(k, 1);
        } else if (t == 2) {
            int p, v; cin >> p >> v;
            values[p - 1] = v;
        } else {
            int l, r; cin >> l >> r;
            ll res = 0;
            for (int j = 0; j < 6; j++) {
                res += ll(values[j]) * ll(ft[j].rsq(l, r));
            }
            cout << res << "\n";
        }
    }
}