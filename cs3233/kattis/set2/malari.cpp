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
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> data;
    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        data.emplace_back(x, y);
    }
    sort(data.begin(), data.end());

    ll units = -1;
    pair<ll, ll> prev = {-1, -1};
    for (auto [x, y]: data) {
        if (x <= prev.second) {
            prev.second = max(prev.second, y);
        } else {
            units += prev.second - prev.first + 1LL;
            prev = {x, y};
        }
    }
    
    units += prev.second - prev.first + 1LL;
    cout << units << "\n";
    if (units * 2 > n) {
        cout << "The Mexicans took our jobs! Sad!" << "\n";
    } else {
        cout << "The Mexicans are Lazy! Sad!" << "\n";
    }
}