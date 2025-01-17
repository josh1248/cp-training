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
    int n, m, k; cin >> n >> m >> k;
    vector<double> houses;
    vector<int> plots;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        plots.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        houses.push_back(x);
    }
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        houses.push_back(x / pow(2, 0.5));
    }
    sort(houses.begin(), houses.end());
    sort(plots.begin(), plots.end());

    int res = 0;
    int h_idx = 0, plot_idx = 0;
    while (true) {
        if (h_idx >= houses.size() || plot_idx >= plots.size()) {
            cout << res << "\n";
            return 0;
        }
        if (houses[h_idx] < plots[plot_idx]) {
            res++;
            h_idx++;
        }
        plot_idx++;
    }
    cout << res << "\n";
}