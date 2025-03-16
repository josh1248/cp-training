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