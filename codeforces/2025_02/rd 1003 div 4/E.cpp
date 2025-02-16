#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (abs(n - m) > k || max(n, m) < k) {
        cout << -1 << "\n";
        return;
    }

    char a = '0', b = '1';
    if (n < m) {
        swap(n, m);
        swap(a, b);
    }

    string t1(k, a);
    cout << t1;
    n -= k;
    while (m > 0) {
        if (m <= k) {
            //cout << "\n" << n << " " << "X\n";
            string t2(m, b);
            cout << t2;
            string t3(min(k, n), a);
            cout << t3;
            break;
        } else {
            //cout << "\nY\n";
            string t2(k, b);
            cout << t2;
            m -= k;
            int use = min(k, n);
            string t3(use, a);
            cout << t3;
            n -= use;
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}