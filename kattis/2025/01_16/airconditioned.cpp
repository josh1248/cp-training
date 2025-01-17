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
    int n; cin >> n;
    vector<pi> v;
    vector<bool> fulfilled(2 * n, false);
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (auto [e, s]: v) {
        bool flag = false;
        for (int i = s; i <= e; i++) {
            if (fulfilled[i]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        fulfilled[e] = true;
        res++;
    }
    cout << res << "\n";
}