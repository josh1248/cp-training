#include <iostream>
#include <algorithm>
#include <cstdio>
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

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    while (true) {
        int v, e; cin >> v >> e;
        if (v == 0) {
            return 0;
        }
        vector<vector<pair<double, int>>> graph(v);
        for (int i = 0; i < e; i++) {
            int x, y; double w; cin >> x >> y >> w;
            graph[x].push_back({w, y});
            graph[y].push_back({w, x});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> estimates(v, 0);
        pq.push({1, 0});
        while (pq.size() > 0) {
            auto [weight, nxt] = pq.top();
            pq.pop();
            if (weight <= estimates[nxt]) {
                continue;
            }
            estimates[nxt] = weight;
            for (auto [edge_weight, neighbour]: graph[nxt]) {
                pq.push({edge_weight * weight, neighbour});
            }
        }
        printf("%.4f\n", estimates[v - 1]);
    }
}