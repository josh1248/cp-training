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

int f(vector<int>& v) {
    int res = 0;
    for (int i = 2; i < v.size(); i++) {
        if (v[i] == v[i - 1] + v[i - 2]) {
            res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        vi v(5);
        cin >> v[0] >> v[1] >> v[3] >> v[4];

        // a3 = a1 + a2
        int res = 0;
        v[2] = v[1] + v[0];
        res = max(f(v), res);

        // a3 = a4 - a2
        v[2] = v[3] - v[1];
        res = max(f(v), res);

        // a3 = a5 - a4
        v[2] = v[4] - v[3];
        res = max(f(v), res);
        cout << res << "\n";
    }
}