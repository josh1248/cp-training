#include <iostream>
#include <algorithm>
#include <cstdio>
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
    int n, k; cin >> n >> k;
    vector<pi> v;
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v.push_back({e, -s});
    }
    multiset<int> classrooms;
    sort(v.begin(), v.end());
    int res = 0;
    for (auto [e, s]: v) {
        s = -s;
        // Greedy:
        // Always re-use the class with the latest end time if possible
        // empty classrooms have endtime -1, use as last resort
        auto p = classrooms.upper_bound(-s);
        if (p != classrooms.end()) {
            classrooms.erase(p);
            classrooms.insert(-e);
            res++;
        } else if (classrooms.size() < k) {
            classrooms.insert(-e);
            res++;
        }
    }
    cout << res << "\n";
}