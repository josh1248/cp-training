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

    int t; cin >> t;
    while (t--) {
        int l, n; cin >> l >> n;
        int min_dist = 0;
        int max_dist = -1e9;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            min_dist = max(min_dist, min(abs(k), abs(l - k)));
            max_dist = max({max_dist, abs(k), abs(l - k)});
        }
        cout << min_dist << " " << max_dist << "\n";
    }
}