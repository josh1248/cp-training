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

// Work backwards: asssume all different colours and we need to combine them into a single colour
// Observe that n - 1 operations are always needed due to sequential union of n initial colour sets
// Can be greedy and combine the colour sets which take the least paint
// optimal: combining the 2 color sets of lowest weight is always globally optimal.
// assume not. track the merges in the alternative set. replacing one element of that set with either
// the smallest element or 2nd smallest set results in a better sum.  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int sz; cin >> sz;
        priority_queue<ll> pq;
        for (int i = 0; i < sz; i++) {
            int k; cin >> k;
            pq.push(-k);
        }
        
        ll ink = 0;
        while (pq.size() >= 2) {
            ll p = 0;
            p += pq.top(); pq.pop();
            p += pq.top(); pq.pop();
            pq.push(p);
            ink += p;
        }
        cout << -ink << "\n";
    }
}