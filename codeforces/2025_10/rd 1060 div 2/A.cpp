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
        string s;
        int n, k; cin >> n >> k >> s;
        int prev_one = -1e9;
        int ans = 0;
        rep(i, 0, n) {
            if (s[i] == '1') {
                if (i - prev_one >= k) {
                    ans++;
                }
                prev_one = i;
            }
        }
        cout << ans << "\n";
    }
}