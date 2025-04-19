#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, n; cin >> R >> C >> n;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    queue<tuple<int, int, int>> q;
    int maxdays = 1;
    rep(i, 0, n) {
        int r1, c1; cin >> r1 >> c1;
        --r1, --c1;
        q.emplace(r1, c1, 1);
        visited[r1][c1] = true;
    }

    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    while (q.size() > 0) {
        auto [r, c, days] = q.front(); q.pop();
        maxdays = max(maxdays, days);

        rep(i, 0, 4) {
            int newr = r + dr[i], newc = c + dc[i];
            if (newr < 0 || newr >= R || newc < 0 || newc >= C || visited[newr][newc]) continue;
            visited[newr][newc] = true;
            q.emplace(newr, newc, days + 1);
        }
    }
    cout << maxdays << "\n";
}