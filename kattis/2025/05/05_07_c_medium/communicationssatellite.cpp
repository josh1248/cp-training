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

    int V; cin >> V;
    vi radii(V);
    vector<pi> coords(V);
    vector<vector<double>> AM(V, vector<double>(V));
    rep(i, 0, V) {
        cin >> coords[i].first >> coords[i].second >> radii[i];
    }
    rep(i, 0, V) {
        rep(j, 0, V) {
            auto [x1, y1] = coords[i];
            auto [x2, y2] = coords[j];
            double dist = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
            AM[i][j] = max(0.0, dist - radii[i] - radii[j]);
        }
    }

    // https://math.stackexchange.com/questions/4526303/do-minimum-spanning-trees-drawn-on-points-in-mathbbr2-always-have-non-inte
    // juz use MST algos as usual without fear of intersection
    vector<bool> visited(V, false);
    priority_queue<tuple<double,int,int>> pq;
    rep(i, 1, V) {
        pq.emplace(-AM[0][i], 0, i);
    }
    visited[0] = true;
    int hits = 0;
    double ans = 0;
    while (hits < V - 1) {
        auto [negd, u, v] = pq.top(); pq.pop();
        double d = -negd;
        if ((visited[u] && visited[v]) || u == v) continue;
        ans += d;
        hits++;
        int src = (visited[u] ? v : u);
        visited[src] = true;
        rep(i, 0, V) {
            if (visited[i]) continue;
            pq.emplace(-AM[src][i], src, i);
        }
    }
    cout << setprecision(9) << fixed << ans << "\n";
}