#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

ll int_pow(int i, int j) {
    ll res = 1;
    while (j--) {
        res *= i;
    }
    return res;
}

class ResGraph {
public:
    int size;
    bool complement;
    bool transpose;
    vector<vector<bool>> am;
    
    ResGraph(int N):
        size(N), complement(false), transpose(false), am(N, vector<bool>(N, false)) {}
    
    void add_vertex() {
        size++;
        for (int i = 0; i < size - 1; i++) {
            am[i].push_back(complement);
        }
        am.push_back(vector<bool>(size, complement));
    }

    void add_edge(int i, int j) {
        if (transpose) {
            am[j][i] = !complement;
        } else {
            am[i][j] = !complement;
        }
    }

    void remove_edge(int i, int j) {
        if (transpose) {
            am[j][i] = complement;
        } else {
            am[i][j] = complement;
        }
    }

    void remove_all_edges(int i) {
        for (int k = 0; k < size; k++) {
            am[k][i] = complement;
            am[i][k] = complement;
        }
    }

    void output() {
        cout << size << "\n";
        for (int i = 0; i < size; i++) {
            ll outs = 0;
            ll p = 1;
            ll res = 0;
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    continue;
                }

                bool connected;
                if (transpose) {
                    connected = (complement != am[j][i]);
                } else {
                    connected = (complement != am[i][j]);
                }
                
                if (connected) {
                    res += p * ll(j);
                    res %= (1'000'000'007LL);
                    outs++;
                    p *= 7;
                    p %= (1'000'000'007LL);
                }
            }
            cout << outs << " " << res << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, q; cin >> v >> e >> q;
    ResGraph graph(v);
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        graph.add_edge(a, b);
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            graph.add_vertex();
        } else if (t == 2) {
            int x, y; cin >> x >> y;
            graph.add_edge(x, y);
        } else if (t == 3) {
            int x; cin >> x;
            graph.remove_all_edges(x);
        } else if (t == 4) {
            int x, y; cin >> x >> y;
            graph.remove_edge(x, y);
        } else if (t == 5) {
            graph.transpose = !graph.transpose;
        } else if (t == 6) {
            graph.complement = !graph.complement;
        }
    }

    graph.output();
}