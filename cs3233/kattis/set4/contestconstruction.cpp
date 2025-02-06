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
    // nodes = problem pairs in sorted order
    // edges = (u, v) <- (v, w) iff u + v >= w
    auto key_of = [&](int u, int v){return u * n + v;};
    unordered_map<int, vi> graph;
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            int sums = data[u] + data[v];
            for (int w = v + 1; w < n; w++) {
                if (data[w] <= sums) {
                    int uv = key_of(u, v);
                    int vw = key_of(v, w);
                    if (graph.count(uv) == 0) graph[uv] = vi();
                    if (graph.count(vw) == 0) graph[vw] = vi();
                    graph[vw].push_back(uv);
                }
            }
        }
    }
    vector<ll> prevs(n * n, 1);
    // we desire length-(k-1) chains
    for (int i = 2; i <= k - 1; i++) {
        // length-i chains
        vector<ll> curr(n * n, 0);
        for (auto& [k, v]: graph) {
            for (auto& nxt: v) {
                curr[nxt] += prevs[k];
            }
        }
        prevs = move(curr);
    }
    
    cout << accumulate(all(prevs), 0ll) << "\n";
}