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
    // -1: not assigned, 0: red, 1: blue
    // use colors to check bipartite graph
    vi color(V, -1);
    vector<string> items(V);
    unordered_map<string, int> mapping;
    rep(i, 0, V) {
        cin >> items[i];
        mapping[items[i]] = i;
    }

    vvi graph(V);
    int E; cin >> E;
    rep(i, 0, E) {
        string x, y; cin >> x >> y;
        int u = mapping[x], v = mapping[y];
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    bool oddcycle = false;
    function<void(int, bool)> dfs = [&](int u, bool curr_color) {
        if (color[u] == 0) {
            if (curr_color) {
                oddcycle = true;
            }
            return;
        } else if (color[u] == 1) {
            if (!curr_color) oddcycle = true;
            return;
        } else {
            color[u] = (curr_color ? 1 : 0);
            for (int& v: graph[u]) {
                dfs(v, !curr_color);
            }
        }
    };
    rep(i, 0, V) {
        if (color[i] == -1) dfs(i, false);
        if (oddcycle) break;
    }

    if (oddcycle) {
        cout << "impossible\n";
    } else {
        rep(i, 0, V) {
            if (color[i] == 0) cout << items[i] << " ";
        }
        cout << "\n";
        rep(i, 0, V) {
            if (color[i] == 1) cout << items[i] << " ";
        }
        cout << "\n";
    }
}