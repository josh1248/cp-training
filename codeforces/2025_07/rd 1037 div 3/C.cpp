#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi towers(n);
        rep(i, 0, n) cin >> towers[i];
        int max_hop = towers[k - 1], starting_height = towers[k - 1];
        sort(all(towers));
        int idx = distance(towers.begin(), lower_bound(all(towers), starting_height));
        bool ok = true;
        for (int i = idx + 1; i < n; i++) {
            if (towers[i] - towers[i - 1] > max_hop) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}