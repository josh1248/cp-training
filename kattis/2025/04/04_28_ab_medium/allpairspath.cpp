#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

const int POS_INF = 1e8, NEG_INF = -1e8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, Q;
    while (cin >> V >> E >> Q) {
        if (V == 0) return 0;
        vvi estimates(V, vi(V, POS_INF));

        // use min in case of self edges or repeated multi edges
        rep(i, 0, E) {
            int u, v, w; cin >> u >> v >> w;
            estimates[u][v] = min(estimates[u][v], w);
        }
        rep(i, 0, V) {
            estimates[i][i] = min(estimates[i][i], 0);
        }

        rep(k, 0, V) {
            rep(i, 0, V) {
                rep(j, 0, V) {
                    if (estimates[i][k] == POS_INF || estimates[k][j] == POS_INF) continue;
                    estimates[i][j] = min(estimates[i][j], estimates[i][k] + estimates[k][j]);
                }
            }
        }

        // https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html#the-case-of-negative-cycles
        rep(i, 0, V) {
            rep(j, 0, V) {
                rep(k, 0, V) {
                    if (estimates[i][k] != POS_INF && estimates[k][j] != POS_INF && estimates[k][k] < 0) {
                        estimates[i][j] = NEG_INF;
                    }
                }
            }
        }
        rep(i, 0, Q) {
            int u, v; cin >> u >> v;
            if (estimates[u][v] == POS_INF) {
                cout << "Impossible\n";
            } else if (estimates[u][v] == NEG_INF) {
                cout << "-Infinity\n";
            } else  {
                cout << estimates[u][v] << "\n";
            }
        }
        cout << "\n";
    }
}