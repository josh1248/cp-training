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
        int seq; cin >> seq;
        int px, py, qx, qy; cin >> px >> py >> qx >> qy;
        vi a(seq);
        rep(i, 0, seq) cin >> a[i];
        double wanted_dist = pow(pow(qx - px, 2) + pow(qy - py, 2), 0.5);
        double total_dist = 0;
        for (int i: a) {
            total_dist += i;
        }
        // cant reach
        if (total_dist - wanted_dist < -0.01) {
            cout << "No\n";
            continue;
        }
        // only 1
        if (seq == 1) {
            cout << (abs(total_dist - wanted_dist) > 0 ? "No" : "Yes") << "\n";
            continue;
        }
        // largest > (all other segments +  wanted dist), cannot (triangle ineq.)
        // otherwise, straighten out all other segments, draw circles around p and q, pick intersection
        sort(all(a));
        double largest = *a.rbegin();
        cout << (largest > (total_dist - largest + wanted_dist) ? "No" : "Yes") << "\n";

    }
}