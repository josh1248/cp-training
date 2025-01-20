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

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "YES" << "\n";
        cin >> n;
        return;
    }
    int curr; cin >> curr;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        int nxt; cin >> nxt;
        if (curr > nxt) {
            flag = true;
        }
        curr = nxt - curr;
    }
    cout << (flag ? "NO" : "YES") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}