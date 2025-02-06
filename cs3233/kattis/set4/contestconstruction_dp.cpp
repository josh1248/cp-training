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
    int n, k; cin >> n >> k;
    vi data(n);
    for (int i = 0; i < n; i++) cin >> data[i];
    sort(all(data));

    ll dp[n][n][k + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (data[i] + data[j] >= data[k]) {
                    dp[j][k][2]++;
                }
            }
        }
    }
    
    for (int x = 3; x < k; x++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (data[i] + data[j] >= data[k]) {
                        dp[j][k][x] += dp[i][j][x - 1];
                    }
                }
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += dp[i][j][k-1];
        }
    }
    cout << sum << "\n";
}