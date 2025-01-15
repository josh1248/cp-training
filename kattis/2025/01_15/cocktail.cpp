#include <iostream>
#include <algorithm>
#include <cstdio>
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

    int n, t; cin >> n >> t;
    vi v(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v[i] = k;
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (v[i] <= (t * (n - i - 1))) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}