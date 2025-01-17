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

    int l, d, n; cin >> l >> d >> n;
    vi birds(n);
    for (int i = 0; i < n; i++) {
        cin >> birds[i];
    }
    birds.push_back(6 - d); // left constraint
    birds.push_back(l + d - 6); // right constraint
    sort(birds.begin(), birds.end());
    int res = 0;
    for (int i = 0; i < n + 1; i++) {
        int l_bound = birds[i] + d;
        int r_bound = birds[i + 1] - d;
        res += (r_bound >= l_bound) ? (1 + (r_bound - l_bound) / d) : 0;
    }
    cout << res << "\n";
}