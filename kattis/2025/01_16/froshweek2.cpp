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
    int n, m; cin >> n >> m;
    vi tasks, quiets;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        tasks.push_back(k);
    }
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        quiets.push_back(k);
    }
    sort(tasks.begin(), tasks.end());
    sort(quiets.begin(), quiets.end());
    int t_idx = 0, q_idx = 0;
    int res = 0;
    while (true) {
        if (t_idx >= n || q_idx >= m) {
            cout << res << "\n";
            return 0;
        }
        if (tasks[t_idx] <= quiets[q_idx]) {
            res++;
            t_idx++;
            q_idx++;
        } else {
            q_idx++;
        }
    }
}