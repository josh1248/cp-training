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
    vi color(V, -1);
    int u, v;
    vvi graph(V);
    rep(i, 0, E) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool oddcycle = false;
    rep(i, 0, V) {
        if (color[i] == -1) {
            vector<pi> stack;
            stack.emplace_back(i, 0);
            while (sz(stack) > 0) {
                auto [u, col] = stack.back(); stack.pop_back();
                if (col == 0 && color[u] == 1) oddcycle = true;
                if (col == 1 && color[u] == 0) oddcycle = true;
                if (color[u] != -1) continue;
                color[u] = col;
                for (int& v: graph[u]) {
                    stack.emplace_back(v, (col == 0 ? 1 : 0));
                }
            }
        }
    }
    cout << (oddcycle ? "no way" : "attend here") << "\n";
}