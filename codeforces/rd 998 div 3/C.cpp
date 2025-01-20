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

// count number of distinct pairs that can formed.
// alice picks a number in a pair -> bob picks the other in a pair.
// alice picks an unpaired number -> bob picks an unpaired number.
// 2Sum-ish solution to count.
void solve() {
    int n, target; cin >> n >> target;
    vector<int> counts(n + 1, 0);
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        int complement = target - k;
        if (complement >= 1 && complement <= n && counts[complement] > 0) {
            pairs++;
            counts[complement]--;
        } else {
            counts[k]++;
        }
    }
    cout << pairs << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}