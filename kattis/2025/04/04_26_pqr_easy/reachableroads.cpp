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

    int t; cin >> t;
    while (t--) {
        int V, E; cin >> V >> E;
        vvi graph(V);
        vector<bool> visited(V, false);
        rep(i, 0, E) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int cc = 0;
        rep(i, 0, V) {
            if (visited[i]) continue;
            vi stack;
            cc++;
            stack.push_back(i);
            while (sz(stack) > 0) {
                int u = stack.back(); stack.pop_back();
                for (int& v: graph[u]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    stack.push_back(v);
                }
            } 
        }
        cout << cc - 1 << "\n";
    }
}