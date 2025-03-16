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

// apply repeated dijkstra's for desired pairs of paths.
vector<vector<pair<ll, int>>> graph;

ll dijkstra(int s, int t) {
    vll estimates(sz(graph), 1e18);
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, s);
    while (sz(pq)) {
        auto [dist, v] = pq.top();
        dist = -dist;
        pq.pop();
        if (estimates[v] <= dist) continue;
        estimates[v] = dist;
        if (v == t) {
            return dist;
        }
        for (auto& [edgeweight, nxt]: graph[v]) {
            ll w = edgeweight + dist;
            if (w < estimates[nxt]) {
                // negate to convert to min pq
                pq.emplace(-w, nxt);
            }
        }
    }
    return -1;
}

// get distances from houses to all possible stores
// solve TSP on that small graph
// https://github.com/stevenhalim/cpbook-code/blob/master/ch3/dp/beepers_UVa10496.cpp
// Held-Karp DP-TSP
#define LSOne(S) ((S) & -(S))

const int MAX_n = 11;

ll dist[MAX_n][MAX_n], memo[MAX_n][1<<(MAX_n-1)]; // Karel + max 10 beepers

// dp(0, (1<<(n-1))-1))
ll dp(int u, int mask) {                        // mask = free coordinates
  if (mask == 0) return dist[u][0];              // close the loop
  ll &ans = memo[u][mask];
  if (ans != -1) return ans;                     // computed before
  ans = 4e18;
  int m = mask;
  while (m) {                                    // up to O(n)
    int two_pow_v = LSOne(m);                    // but this is fast
    int v = __builtin_ctz(two_pow_v)+1;          // offset v by +1
    ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v)); // keep the min
    m -= two_pow_v;
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E; cin >> V >> E;
    graph = vector<vector<pair<ll, int>>>(V);
    rep(i, 0, E) {
        int u, v; ll w; cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }
    int stores; cin >> stores;
    vi v(stores + 1);
    v[0] = 0;
    rep(i, 0, stores) {
        cin >> v[i + 1];
    }
    rep(i, 0, stores + 1) {
        rep(j, i + 1, stores + 1) {
            dist[i][j] = dist[j][i] = dijkstra(v[i], v[j]);
        }
    }

    memset(memo, -1, sizeof(memo));
    cout << dp(0, ((1<<stores)-1)) << "\n";
    return 0;
}