#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(10) << fixed;
    double currspeed = 100;
    int n, p, k; cin >> n >> p >> k;
    int prev = 0;
    double totaltime = 0;
    rep(i, 0, n) {
        int curr; cin >> curr;
        totaltime += (curr - prev) * currspeed / 100.0;
        currspeed += p;
        prev = curr;
    }
    totaltime += (k - prev) * currspeed / 100.0;
    cout << totaltime << "\n";
}