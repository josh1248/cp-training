#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

void solve() {
    int v;
    cin >> v;
    
    vector<set<int>> graph(v + 1);
    for (int i = 0; i < v - 1; i++) {
        int u, v; cin >> u >> v;
        graph[v].insert(u);
        graph[u].insert(v);
    }

    vi mvers = {0};
    int mval = 0;
    for (int i = 1; i < v + 1; i++) {
        if (graph[i].size() > mval) {
            mvers.clear();
            mval = graph[i].size();
            mvers.push_back(i);
        } else if (graph[i].size() == mval) {
            mvers.push_back(i);
        }
    }

    if (mvers.size() >= 3) {
        cout << 2 * (mval - 1) + 1 << "\n";
        return;
    } else if (mvers.size() == 2) {
        cout << 2 * (mval - 1) + ((graph[mvers[0]].count(mvers[1]) > 0) ? 0 : 1) << "\n";
        return;
    }


    for (int i: graph[mvers[0]]) {
        graph[i].erase(mvers[0]);
    }
    graph[mvers[0]].clear();

    int mvers2 = 0;
    int mval2 = 0;
    for (int i = 1; i < v + 1; i++) {
        if (graph[i].size() > mval2) {
            mvers2 = i;
            mval2 = graph[i].size();
        }
    }

    cout << mval + mval2 - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}