#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define int ll
#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<pi> data;
    for (int i = 0; i < m; i++) {
        int weight, cost; cin >> weight >> cost;
        data.emplace_back(cost, min(weight, n));
    }
    sort(all(data));
    int req = n * k;
    int ans = -1;
    for (auto& [cost, weight]: data) {
        ans = cost;
        req -= weight;
        if (req <= 0) break;
    }

    if (req > 0) {
        cout << "Unpossible\n";
    } else {
        cout << ans << "\n";
    }
}
// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}