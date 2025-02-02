#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

ll n;
vi adj(2e5+1);
vvi graph(2e5+1);
vector<ll> lows(2e5+1);
vector<ll> highs(2e5+1);
ll ans = -1;

// calculate +1 operations from child nodes 
ll dfs(int n, int parent) {
    ll ops_prev = 0;
    for (int v: graph[n]) {
        if (v == parent) {
            continue;
        }
        ops_prev += dfs(v, n);
    }

    // now, calculate immediate ops needed due to gap between it and child nodes
    // obtain value where immediate ops can be minimized
    ll ops_now = 0; ll min_possible = lows[n];
    for (int v: graph[n]) {
        if (v == parent) {
            continue;
        }

        // all other cases: no back ops required
        ll check = highs[v];
        if (highs[n] < check) {
            ops_now += lows[v] - highs[n];
            min_possible = highs[n];
        } else if (lows[n] <= check && check <= highs[n]) {
            min_possible = max(min_possible, check);
        }
    }

    lows[n] = highs[n] = min_possible;

    return ops_prev + ops_now;
}

void solve() {
    cin >> n;
    lows.assign(n + 1, 0); highs.assign(n + 1, 0); graph.assign(n + 1, vi()); adj.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> lows[i] >> highs[i];
    }

    
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        adj[u]++; adj[v]++;
    }

    // find leaf node
    cout << dfs(1, -1) + lows[1] << "\n";
    // for (int i = 1; i <= n; i++) {
    //     if (adj[i] == 1) {
    //         // cout << i << ": " << dfs(i, -1) << "with val " << lows[i] << " - " << highs[i]  << "\n";
    //         cout << dfs(i, -1) + lows[i] << "\n";
    //         return;
    //     }
    // }
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}