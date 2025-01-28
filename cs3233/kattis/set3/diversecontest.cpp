#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    map<string, int> order; int high = 0;
    vi data(n);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int mask = 0;
        for (int j = 0; j < t; j++) {
            string s; cin >> s;
            if (order.count(s) == 0) {
                order[s] = high;
                high++;
            }
            mask |= (1 << order[s]);
        }
        data[i] = mask;
    }

    ll res = 0; vi hits(high, 0);
    for (int i = 0; i < (1 << high); i++) {
        if (__builtin_popcount(i)!=k)continue;
        hits.assign(high, 0);
        for (int d: data) {
            for (int j = 0; j < high; j++) {
                hits[j] += ((d & (1 << j)) ? 1 : 0);
                if (hits[j] > (k / 2)) {goto nxt;}
            }
        }
        res++;
        nxt: cout << "\n";continue;
    }
    cout << res << "\n";
}