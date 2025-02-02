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
    int n, m; cin >> n >> m;
    vector<int> order(n, -1);
    // cows must have a hand that is all a fixed modulo n
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int mod; cin >> mod;
        mod = mod % n;
        order[mod] = i;
        for (int j = 1; j < m; j++) {
            int check; cin >> check;
            if (check % n != mod) {
                flag = true;
            }
        }
    }

    if (flag) {
        cout << -1 << "\n";
        return;
    }

    for (int i: order) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}