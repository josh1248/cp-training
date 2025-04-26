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
    vi cnts(V + 1, 0);
    rep(i, 0, E) {
        int u, v; cin >> u >> v;
        cnts[u]++, cnts[v]++;
    }
    rep(i, 1, V + 1){
        cout << cnts[i] - i << "\n";
    }
}