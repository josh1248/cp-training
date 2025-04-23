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

    int t; cin >> t;
    while (t--) {
        int n, target; cin >> n >> target;
        vvi graph(3601);
        rep(i, 0, n) {
            int x; cin >> x;
            if (x == 0) continue;
            rep(j, 0, 3601) {
                if (j + x >= 0 && j + x <= 3600) {
                    graph[j].emplace_back(j + x);
                } else if (j + x < 0) {
                    graph[j].emplace_back(0);
                } else {
                    graph[j].emplace_back(3600);
                }
            }
        }

        vi dist(3601, -1);
        dist[0] = 0;
        queue<int> q;
        q.emplace(0);
        while (q.size() > 0) {
            int u = q.front(); q.pop();
            for (int& v: graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                }
            }
        }
        rep(i, target, 3601) {
            if (dist[i] != -1) {
                cout << dist[i] << " " << i - target << "\n";
                break;
            }
        }
    }
}