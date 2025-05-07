#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vvi AM;

int prim(int V) {
    int ans = 0;
    vector<bool> visited(V, false);
    priority_queue<tuple<int,int,int>> pq;
    rep(i, 0, V) {
        pq.emplace(-AM[0][i], 0, i);
    }
    visited[0] = false;
    int hits = 0;
    while (sz(pq) > 0 || hits < V - 1) {
        auto [negw, u, v] = pq.top(); pq.pop();
        int w = -negw;
        if (visited[u] && visited[v]) continue;
        else if (!visited[u]) {
            visited[u] = true;
            ans += w;
            hits++;
            rep(i, 0, V) {
                if (!visited[i]) {
                    pq.emplace(-AM[u][i], u, i);
                }
            }
        } else {
            visited[v] = true;
            ans += w;
            hits++;
            rep(i, 0, V) {
                if (!visited[i]) {
                    pq.emplace(-AM[v][i], u, i);
                }
            }
        }
    }

    return 2 * ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V; cin >> V;
    AM = vvi(V, vi(V));
    vector<pi> pts(V);
    rep(i, 0, V) cin >> pts[i].first >> pts[i].second;
    rep(i, 0, V) {
        rep(j, 0, V) {
            AM[i][j] = abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second);
        }
    }

    cout << prim(V) << "\n";
}