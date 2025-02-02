#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            if (k <= 2 * max(i, n - i - 1)) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    } 
}