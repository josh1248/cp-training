#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

int dp[1<<9];

int flip(int r, vi positions) {
    for (int p: positions) r ^= 1<<p;
    return r;
}

const vvi flips = {
    {0,1,3},
    {0,1,2,4},
    {1,2,5},
    {0,3,4,6},
    {1,3,4,5,7},
    {2,4,5,8},
    {3,6,7},
    {4,6,7,8},
    {5,7,8}
};

int bfs() {
    memset(dp, -1, sizeof(dp));
    queue<pi> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto& [mask, depth] = q.front(); q.pop();
        if (dp[mask] != -1) continue;

        dp[mask] = depth;
        for (const auto& f: flips) {
            int nxt = flip(mask, f);
            if (dp[nxt] == -1) q.push({nxt, depth+1});
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bfs();

    int t; cin >> t;
    while (t--) {
        int mask = 0; char c;
        for (int i = 0; i < 9; i++) {
            cin >> c;
            if (c == '*') {
                mask += 1<<i;
            }
        }
        cout << dp[mask] << "\n";
    }
}