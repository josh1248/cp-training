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
    int n, cap; cin >> n >> cap;
    int high = 0;
    unordered_map<string, int> m;
    vvi store;
    for (int i = 0; i < n; i++) {
        string s; int c;
        cin >> c >> s;
        if (m.count(s) == 0) {
            m.emplace(s, high);
            store.push_back(vi());
            high++;
        }
        store[m[s]].push_back(c);
    } 

    bool dp[high + 1][cap + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 0; i < high; i++) {
        for (int item: store[i]) {
            for (int j = 0; j <= cap; j++) {
                if (dp[i][j]) dp[i + 1][j] = true;

                if (dp[i][j] && j + item <= cap) {
                    dp[i + 1][j + item] = true;
                }
            }
        }
    }

    for (int i = cap; i >= 0; i--) {
        if (dp[high][i]) {
            cout << i << "\n";
            break;
        }
    }
}   