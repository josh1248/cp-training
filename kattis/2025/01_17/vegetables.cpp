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

// always need to cut largest vegetable to reduce vegetable.
// additionally, in optimal solution, consider pieces belonging to the same original vegetable
// it always improves the ratio / keeps it the same if pieces are of equal length.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   

    double r;
    int n;
    cin >> r >> n;
    double low = 1e9;
    priority_queue<tuple<double, int, int>> pq;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        pq.push({k, k, 1});
        low = min(low, double(k));
    }

    int cuts = 0;
    while (double(low) / get<0>(pq.top()) < r) {
        auto [weight, k, denom] = pq.top();
        pq.pop();
        double l = double(k) / (denom + 1);
        pq.push({l, k, denom + 1});
        cuts++;
        low = min(low, l);
    }
    cout << cuts << "\n";
}