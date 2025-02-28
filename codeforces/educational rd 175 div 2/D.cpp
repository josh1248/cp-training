#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;


#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

const int MOD = 998244353;

vvi graph, depth_graph;
vll res;
int max_depth;

void dfs(int v, int depth) {
    //if (v < 0) return;
    // cout << v << " ";
    depth_graph[depth].push_back(v);
    max_depth = max(max_depth, depth);
    for (int& nxt: graph[v]) {
        dfs(nxt, depth + 1);
    }
}

void solve() {
    int n; cin >> n;
    graph.clear(); depth_graph.clear();
    graph.assign(n, vi()), depth_graph.assign(n + 1, vi());
    res.assign(n, 0ll);
    max_depth = 0;
    vi parents(n);
    parents[0] = -1;
    int p;
    rep(i, 0, n - 1) {
        cin >> p; p--;
        parents[i + 1] = p;
        graph[p].push_back(i + 1);
    }
    dfs(0, 0);

    ll acc = 1;
    res[0] = 1;
    ll depth_total_paths = 0;
    for (int& nxt: depth_graph[1]) {
        res[nxt] = 1;
        depth_total_paths++;
        acc++;
    }

    rep(d, 1, max_depth + 1) {
        ll curr_total_paths = 0;
        for (int& v: depth_graph[d + 1]) {
            res[v] = depth_total_paths - res[parents[v]];
            curr_total_paths += res[v];
            curr_total_paths %= MOD;
        }
        depth_total_paths = curr_total_paths;
        acc += curr_total_paths;
        acc %= MOD;
    }
    cout << (acc > 0 ? acc : acc + MOD) << "\n";
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}