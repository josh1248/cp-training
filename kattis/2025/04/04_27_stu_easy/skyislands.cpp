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

    int V, E; cin >> V >> E;
    vvi graph(V);
    rep(i, 0, E) {
        int u, v; cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    int cc = 0;
    vector<bool> visited(V, false);
    rep(i, 0, V) {
        if (!visited[i]) {
            cc++;
            vi stack;
            stack.emplace_back(i);
            while (sz(stack) > 0) {
                int u = stack.back(); stack.pop_back();
                visited[u] = true;
                for (int& v: graph[u]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    stack.push_back(v);
                }
            }
        }
    }

    cout << (cc == 1 ? "YES" : "NO") << "\n";
}