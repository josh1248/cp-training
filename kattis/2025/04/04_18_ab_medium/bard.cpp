#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e; cin >> n >> e;
    vector<set<int>> villagers(n);
    int totalsongs = 0;
    rep(i, 0, e) {
        int k; cin >> k;
        bool hasbard = false;
        vi ns;
        rep(i, 0, k) {
            int x; cin >> x;
            if (x == 1) {
                hasbard = true;
            }
            ns.push_back(x);
        }

        if (hasbard) {
            totalsongs++;
            for (int v: ns) {
                villagers[v - 1].insert(i);
            }
        } else {
            set<int> total;
            for (int v: ns) {
                total.insert(all(villagers[v - 1]));
            }
            for (int v: ns) {
                villagers[v - 1] = total;
            }
        }
    }

    rep(i, 0, n) {
        if (sz(villagers[i]) == totalsongs) {
            cout << i + 1 << "\n";
        }
    }
    return 0;
}