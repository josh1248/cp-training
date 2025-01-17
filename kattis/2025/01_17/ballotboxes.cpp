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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int c, boxes; cin >> c >> boxes;
        if (c == -1) {
            return 0;
        }
        boxes -= c;
        
        priority_queue<tuple<double, int, int>> pq;
        for (int i = 0 ; i < c; i++) {
            int x; cin >> x;
            pq.push({x, x, 1});
        }
        
        while (boxes--) {
            auto [weight, population, b] = pq.top();
            pq.pop();
            pq.push({double(population) / (b + 1), population, b + 1});
        }
        
        auto [_, population, b] = pq.top();
        cout << (population + b - 1) / b << "\n";
    }
}