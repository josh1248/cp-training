#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; double fee; cin >> n >> fee;
    
    // space opt - online algorithm, no need to store fees
    // time opt - no need to consider buying along monotone increasing,
    // no need to sell along monotone decreasing
    double buy = 0, sell = 100.0, prev = 100000.0;
    for (int i = 0; i < n; i++) {
        double curr; cin >> curr;
        if (curr > prev) {
            sell = max(sell, buy * curr - fee);
        } else {
            buy = max(buy, (sell - fee) / curr);
        }
        prev = curr;
    }
    cout << fixed << setprecision(8);
    cout << sell << "\n";
}