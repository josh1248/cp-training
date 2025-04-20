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
    vvi graph(n);
    rep(i, 0, n / 2 + 1) {
        int u, v; cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vi hits;
    rep(i, 0, n) {
        if (sz(graph[i]) > 1) hits.emplace_back(i);
    }

    if (sz(hits) == 1) cout << 1 + hits[0] << " " << 1 + hits[0] << "\n";
    else cout << 1 + min(hits[0], hits[1]) << " " << 1 + max(hits[0], hits[1]) << "\n";
    return 0;
}