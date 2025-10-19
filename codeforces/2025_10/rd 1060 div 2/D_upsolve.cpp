#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

void solve() {
    int V; cin >> V;
    vector<unordered_set<int>> graph(V);
    // mark nodes of even distance from node 1 true colour, odd distance false colour
    vector<bool> color(V);
    rep(i, 0, V - 1) {
        int u, v; cin >> u >> v;
        graph[u - 1].insert(v - 1);
        graph[v - 1].insert(u - 1);
    }

    vector<tuple<int, int, bool>> stack;
    stack.emplace_back(0, -1, true);
    // DFS coloring
    while (stack.size() > 0) {
        auto [u, parent, u_color] = stack.back(); stack.pop_back();
        color[u] = u_color;
        for (int v: graph[u]) {
            if (v != parent) stack.emplace_back(v, u, !u_color);
        }
    }
    
    // exempt end node from cutting scheme
    vector<unordered_set<int>> num_neighbours_false(V + 1), num_neighbours_true(V + 1);
    rep(i, 0, V - 1) {
        if (color[i]) {
            num_neighbours_true[graph[i].size()].insert(i);
        } else {
            num_neighbours_false[graph[i].size()].insert(i);
        }
    }

    bool curr_color = true;
    int nodes_left = V;
    // kill all nodes slowly until end node left
    vector<string> instrs;
    while (nodes_left > 1) {
        // kill a leaf node of opposite color
        // if not possible, stall a turn
        if ((curr_color && num_neighbours_false[1].size() == 0) || 
            (!curr_color && num_neighbours_true[1].size() == 0)) {
            instrs.push_back("1");
            curr_color = !curr_color;
        }

        int terminal;
        if (curr_color) {
            terminal = *num_neighbours_false[1].begin();
            num_neighbours_false[1].erase(num_neighbours_false[1].begin());
        } else {
            terminal = *num_neighbours_true[1].begin();
            num_neighbours_true[1].erase(num_neighbours_true[1].begin());
        }
        nodes_left--;

        // propagate to remaining neighbour
        int v = *graph[terminal].begin();
        int curr_sz = int(graph[v].size());
        graph[v].erase(terminal);
        if (v != V - 1) {
            if (color[v]) {
                num_neighbours_true[curr_sz].erase(v);
                num_neighbours_true[curr_sz - 1].insert(v);
            } else {
                num_neighbours_false[curr_sz].erase(v);
                num_neighbours_false[curr_sz - 1].insert(v);
            }
        }
        
        curr_color = !curr_color;
        instrs.push_back("2 " + to_string(terminal + 1));
        instrs.push_back("1");
    }

    cout << "\n";
    cout << instrs.size() << "\n";
    for (string& s: instrs) {
        cout << s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}