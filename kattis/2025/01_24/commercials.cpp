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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, base; cin >> k >> base;
    int profitNow = 0, maxSeen = 0;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        x -= base;
        profitNow = max(0, profitNow + x);
        maxSeen = max(maxSeen, profitNow);
    }
    cout << maxSeen << "\n";
}