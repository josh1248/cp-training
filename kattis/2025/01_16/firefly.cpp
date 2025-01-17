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

    int n, h; cin >> n >> h;
    vi btm, top;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (flag) {
            btm.push_back(k);
        } else {
            top.push_back(h - k);
        }
        flag = !flag;
    }
    sort(btm.begin(), btm.end());
    sort(top.begin(), top.end());
    int mins_broken = 1e7, mins_height;
    for (int i = 1; i <= h; i++) {
        int btm_broken = distance(lower_bound(btm.begin(), btm.end(), i), btm.end());
        int top_broken = distance(top.begin(), lower_bound(top.begin(), top.end(), i));
        int res = btm_broken + top_broken;
        if (res < mins_broken) {
            mins_broken = res;
            mins_height = 1;
        } else if (res == mins_broken) {
            mins_height++;
        }
    }
    cout << mins_broken << " " << mins_height << "\n";
}