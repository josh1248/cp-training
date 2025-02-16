#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vi a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        bool flag = false;
        sort(all(b));
        a[0] = min(a[0], b[0] - a[0]);
        for (int i = 1; i < n; i++) {
            int prev = a[i-1], curr = a[i];
            // find smallest possible number that is still >= curr
            // prev == val - a[i]
            // val == prev + a[i]
            int ideal = prev + a[i];
            auto it = lower_bound(all(b), ideal);

            if (prev > curr) {
                if (it == b.end()) { // no possible choices to give >= prev
                    cout << "NO\n";
                    flag = true;
                    break;
                }
                a[i] = *it - curr;
            } else {
                if ((it != b.end()) && (prev <= (*it - curr))) {
                    a[i] = min(a[i], *it - curr);
                }
            }
        }
        if (!flag) cout << "YES\n";
    }
}