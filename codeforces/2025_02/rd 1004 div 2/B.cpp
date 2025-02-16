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
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

void solve() {
    int n; cin >> n;
    map<int, int> holds;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (holds.count(x) == 0) {
            holds[x] = 0;
        }
        holds[x]++;
    }

    while (sz(holds)) {
        // for lowest pair, take 2 (throw one to the other bag, leave one untouched in original)
        // greedily transform the remaining
        auto& [k, v] = *holds.begin();
        if (v == 1) {
            cout << "No\n";
            return;
        }

        if (v >= 2 && holds.count(k + 1) == 0) {
            holds[k + 1] = 0;
        }
        if (v >= 2) holds[k + 1] += v - 2;
        holds.erase(holds.begin());
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}