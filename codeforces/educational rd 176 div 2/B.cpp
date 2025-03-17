#include <bits/stdc++.h>
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
        vector<ll> values(n);
        rep(i, 0, n) cin >> values[i];
        ll best = 0;
        // consider all possible last elements
        // last element at right extreme
        // vector<ll> sorted(values);
        // sorted.pop_back();
        // sort(all(sorted), greater<ll>());
        
        // ll r = values[n - 1];
        // rep(i, 0, k) {
        //     r += sorted[i];
        // }
        // best = max(best, r);
        
        // // last element at left extreme
        // vector<ll> s(values);
        // s.erase(s.begin());
        // ll l = values[0];
        // rep(i, 0, k) {
        //     l += s[i];
        // }
        // best = max(best, l);

        // if (k == 1) {
        //     cout << best << "\n";
        //     continue;
        // }

        // all middle elements
        // middle elements must be flanked by blue balls on both sides
        vector<int> left, right;
        for (int i = n - 1; i >= 1; i--) {
            right.emplace_back(values[i]);
        }
        rep(i, 0, n) {
            ll total = values[i];
            int topick = k;
            vi lsort(left), rsort(right);
            if (k == 1) {
                if (i == 0 || i == n - 1) {
                    best = max(best, values[0] + values[n - 1]);
                } else {
                    best = max(best, values[i] + max(values[0], values[n - 1]));
                }
                continue;
            }
            sort(all(lsort)), sort(all(rsort));
            if (sz(lsort) > 0) {
                total += lsort.back();
                topick--;
                lsort.pop_back();
            }
            if (sz(rsort) > 0) {
                total += rsort.back();
                topick--;
                rsort.pop_back();
            }
            vi combined(lsort);
            combined.insert(combined.end(), all(rsort));
            sort(all(combined), greater<ll>());
            rep(i, 0, topick) {
                total += combined[i];
            }
            best = max(best, total);
            right.pop_back();
            left.emplace_back(values[i]);
        }
        cout << best << "\n";
    }
}