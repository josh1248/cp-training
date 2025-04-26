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
        vi v(n);
        rep(i, 0, n) cin >> v[i];
        sort(all(v));
        vi distinct_choices;
        rep(i, 0, n) {
            bool ok = false;
            int left = i, right = n - i - 1;
            // absolute diff <= 1 -> can minimize
            // remove k from the over-weighted side as needed
            if (abs(right - left) <= k + 1) {
                ok = true;
            }
            if (ok) {
                if (sz(distinct_choices) == 0 || distinct_choices[sz(distinct_choices) - 1] != v[i]) {
                    distinct_choices.push_back(v[i]);
                }
            }
        }
        cout << *rbegin(distinct_choices) - *begin(distinct_choices) + 1 << "\n";
    }
}