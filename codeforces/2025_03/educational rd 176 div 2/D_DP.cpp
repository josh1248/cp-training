#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

// knapsack stones
ll pows[50];
void populate_pows() {
    pows[0] = 1;
    rep(i, 1, 50) {
        pows[i] = (pows[i - 1] << 1);
    } 
}

ll DP[50][63][63];

void populate_knapsack() {
    // iterative approach
    // more legit since we dont know knapsack capacity beforehand
    rep(curr, 1, 50) {
        rep(i, 0, 63) {
            rep(j, 0, 63) {
                // dont use current element at all
                DP[curr][i][j] = min(DP[curr][i][j], DP[curr - 1][i][j]);
                
                // remove current element in left if possible
                if (i >= curr) {
                    DP[curr][i][j] = min(DP[curr][i][j], (1ll << curr) + DP[curr - 1][i - curr][j]);
                }

                if (j >= curr) {
                    DP[curr][i][j] = min(DP[curr][i][j], (1ll << curr) + DP[curr - 1][i][j - curr]);
                }
            }
        }
    }
}

// recursive approach
// ll knapsack(int curr, int i, int j) {
//     // no more
//     if (i >= 63 || j >= 63) return 4e18;
//     else if (curr >= 50) return 0;
//     ll& ans = DP[curr][i][j];
//     if (ans != -1) return ans;

//     ans = 4e18;
//     // dont use
//     ans = min(ans, knapsack(curr + 1, i, j));
//     // put into i
//     ans = min(ans, (1ll << curr) + knapsack(curr + 1, i + curr, j));
//     ans = min(ans, (1ll << curr) + knapsack(curr + 1, i, j + curr));
//     return ans;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    populate_pows();
    rep(i, 0, 50) {
        rep(j, 0, 63) {
            rep(k, 0, 63) {
                DP[i][j][k] = 1e18;
            }
        }
    }
    // start node
    DP[0][0][0] = 0;
    populate_knapsack();
    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        ll mins = 4e18;
        rep(i, 0, 63) {
            rep(j, 0, 63) {
                if ((x >> i) == (y >> j)) {
                    // must be exact subset sum match
                    mins = min(mins, DP[49][i][j]);
                }
            }
        }
        cout << mins << "\n";
    }
}