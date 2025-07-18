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
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        // lbound, rbound, money
        vector<tuple<int, int, int>> casinos(n);
        rep(i, 0, n) {
            int l, r, real; cin >> l >> r >> real;
            casinos[i] = {l, r, real};
        }
        sort(all(casinos));

        for (auto [l, r, real]: casinos) {
            if (l <= k && k <= r && real > k) {
                // always take the money
                // always optimal due to l <= real <= r restriction
                k = real;
            }
        }
        cout << k << "\n";
    }
}