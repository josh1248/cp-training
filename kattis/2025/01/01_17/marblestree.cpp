#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

vi up;
vvi down;
vi marbles;
vvi depths;

void bfs(int d, int v) {
    if (d >= depths.size()) {
        depths.push_back(vi());
    }
    depths[d].push_back(v);
    for (int nxt: down[v]) {
        bfs(d + 1, nxt);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int v; cin >> v;
        if (v == 0) {
            return 0;
        }

        for (int i = 0; i < v; i++) {
            int x, m, n; cin >> x >> m >> n;
            marbles[x] = m;
            for (int j = 0; j < n; j++) {
                int k; cin >> k;
                down[x].push_back(k);
                up[k] = x;
            }
        }

        for (int d = 0; d < depths.size(); d++) {
            for (int z = 0; z < depths[d].size(); z++) {
                cout << d[z]
            }
        }
    }
}