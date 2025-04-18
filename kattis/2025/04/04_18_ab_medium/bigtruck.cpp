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

    int n; cin >> n;
    vi items(n);
    vector<vector<pi>> graph(n);
    rep(i, 0, n) cin >> items[i];
    int E; cin >> E;
    rep(i, 0, E) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    vi distestimate(n, 1e9), itemestimate(n, -1);
    itemestimate[0] = items[0];
    distestimate[0] = 0;
    priority_queue<tuple<int, int, int>> pq;
    pq.push({-0, items[0], 0});
    while (sz(pq) > 0) {
        auto [negdist, it, u] = pq.top(); pq.pop();
        // cout << negdist << " " << it << " " << u << "\n";
        ll dist = -negdist;
        if (distestimate[u] < dist || itemestimate[u] > it) continue;
        // else if (u == n - 1) break;

        for (auto& [v, w]: graph[u]) {
            ll targetw = w + dist;
            ll targetitems = it + items[v];
            if (targetw < distestimate[v]) {
                distestimate[v] = targetw;
                itemestimate[v] = targetitems;
                pq.push({-targetw, targetitems, v});
            } else if (targetw == distestimate[v] && targetitems > itemestimate[v]) {
                itemestimate[v] = targetitems;
                pq.push({-targetw, targetitems, v});
            }
        }
    }
    if (distestimate[n - 1] == 1e9) {
        cout << "impossible\n";
        return 0;
    }
    cout << distestimate[n - 1] << " " << itemestimate[n - 1] << "\n";
}