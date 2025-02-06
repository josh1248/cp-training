#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    int dp[n][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        if (s[i] == '.') {
            copy(all(dp[i-1]), dp[i]);
            dp[i][2] += 2;
            dp[i][1] += 2;
            dp[i][0]++;
        } else if (s[i] == 'S') {
            dp[i][2] = 1e9;
            dp[i][1] = dp[i-1][2] + 2;
            dp[i][0] = dp[i-1][1] + 2;
        } else {
            dp[i][2] = min(dp[i-1][1] + 2, dp[i-1][2] + 2);
            dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 2);
            dp[i][0] = dp[i-1][0] + 1;
        }
    }

    int h = *min_element(all(dp[n-1]));
    cout << (h >= 1e9 ? -1 : h) << "\n"; 
}