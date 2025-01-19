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
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        ll hidden_perimeter = 0;
        for (int i = 0; i < n; i++) {
            int xi, yi; cin >> xi >> yi;
            if (i != 0) {
                hidden_perimeter += 2 * (m - xi + m - yi);
            }
        }
        cout << 4 * m * n - hidden_perimeter << "\n";
    }
}