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

    int N; cin >> N;
    vector<vector<pair<int, double>>> graph(N + 1);
    vector<double> maxProd(N + 1, 0);
    vector<double> received(N + 1, 0);
    vector<bool> is_source(N + 1, true);
    maxProd[0] = 4e18;
    received[0] = 1e18;

    rep(i, 1, N + 1) {
        cin >> maxProd[i];
        int k; cin >> k;
        rep(j, 0, k) {
            int x, y; cin >> x >> y;
            graph[i].emplace_back(x, y / 100.0);
            is_source[x] = false;
        }
    }

    rep(i, 1, N + 1) {
        if (is_source[i]) {
            // for topological sort purposes
            graph[0].emplace_back(i, 1);
        }
    }

    vector<int> order;
    vector<bool> seen(N + 2, false);

    function<void(int)> toposort = [&](int v) {
        seen[v] = true;
        for (auto& [neighbour, _]: graph[v]) {
            if (!seen[neighbour]) toposort(neighbour);
        }
        order.push_back(v);
    };

    toposort(0);
    reverse(all(order));
    vi maxed;
    rep(x, 0, N + 1) {
        int i = order[x];
        // cout << i << " " << received[i] << " " << maxProd[i] << "\n";
        if (received[i] - maxProd[i] > 0.00001) {
            maxed.push_back(i);
        }
        double outflow = min(maxProd[i], received[i]);
        
        for (auto& [neighbour, weight]: graph[i]) {
            received[neighbour] += weight * outflow;
        }
    }

    sort(all(maxed));
    for (int i: maxed) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
