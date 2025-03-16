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

// https://github.com/stevenhalim/cpbook-code/blob/master/ch3/dp/beepers_UVa10496.cpp
// Held-Karp DP-TSP
#define LSOne(S) ((S) & -(S))

const int MAX_n = 16;

int dist[MAX_n][MAX_n], memo[MAX_n][1<<(MAX_n-1)]; // Karel + max 10 beepers

// dp(0, (1<<(n-1))-1)), where n is the number of non-source nodes
int dp(int u, int mask) {                        // mask = free coordinates
  if (mask == 0) return 0;              // no need to go back
  int &ans = memo[u][mask];
  if (ans != -1) return ans;                     // computed before
  ans = 2000000000;
  int m = mask;
  while (m) {                                    
    int two_pow_v = LSOne(m);
    int v = __builtin_ctz(two_pow_v)+1;          // change to ctzll if long long needed
    ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v));
    m -= two_pow_v;
  }
  return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s; cin >> n >> m >> s;
    vi vertexcosts(n); rep(i, 0, n) cin >> vertexcosts[i];

    memset(memo, -1, sizeof(memo));
    graph.assign(n, vector<pair<ll, int>>());
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }
    
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            dist[i][j] = dist[j][i] = dijkstra(i, j);
        }
    }

    int res = dp(0, (1<<(n-1))-1);
    sort(all(vertexcosts));
    // always optimal to smite k longest monsters
    rep(i, 0, n - s) {
        res += vertexcosts[i];
    }
    cout << res << "\n";
    return 0;
}