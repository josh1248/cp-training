#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
using namespace std;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        bool resting = false;
        int streak = 0;
        vi v(n);
        rep(i, 0, n) cin >> v[i];
        for (int d: v) {
            if (resting) {
                resting = false;
            } else if (d == 0) {
                streak++;
                if (streak == k) {
                    ans++;
                    streak = 0;
                    resting = true;
                }
            } else {
                streak = 0;
            }
        }
        cout << ans << "\n";
    }
}