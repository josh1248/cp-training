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

ll dist_used(vector<pi> v, int k) {
    // go to furthest coordinate (trip must be made anyway)
    // with leftovers, help the next furthest coordinate
    ll dist = 0; ll leftover = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [coord, req] = v[i];
        req -= leftover;
        if (req <= 0) {
            leftover = -req;
            continue;
        } else {
            int trips = (req + k - 1) / k;
            dist += ll(2 * trips * coord);
            leftover = trips * k - req;
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<pi> minus, plus;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x < 0) {
            minus.push_back({-x, y});
        } else {
            plus.push_back({x, y});
        }
    }
    sort(minus.rbegin(), minus.rend());
    sort(plus.rbegin(), plus.rend());

    cout << dist_used(minus, k) + dist_used(plus, k) << "\n";
}