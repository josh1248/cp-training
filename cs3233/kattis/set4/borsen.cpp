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
    vector<double> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    //buy - number of stocks, sell - money
    vector<double> buy(n + 1, -1), sell(n + 1, -1);
    buy[0] = 0.0, sell[0] = 100.0;
    for (int i = 0; i < n; i++) {
        buy[i + 1] = max(buy[i], (sell[i] - fee) / data[i]);
        sell[i + 1] = max(sell[i], buy[i] * data[i] - fee);
    }

    // if path required - store parent of max value at each point
    // trace decisions ending at sell[n]
    // simulate the actual process
  
    cout << fixed << setprecision(8);
    cout << sell[n] << "\n";
}