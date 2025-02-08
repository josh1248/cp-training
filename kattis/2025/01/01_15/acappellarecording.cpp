#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;
    vi v;
    for (int i = 0; i < n; i++) {
        int k; cin >> k; v.push_back(k);
    }
    sort(v.begin(), v.end());
    int base = v[0]; int res = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] - base > t) {
            base = v[i];
            res++;
        }
    }
    cout << res << "\n";
}