#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

// 'g++ -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);  

    int n; cin >> n;
    vi coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(all(coins), greater<>());

    vi cc_dp_soln; cc_dp_soln.push_back(0);
    vi cc_dp_parent; cc_dp_parent.push_back(-1);

    vi greedy_soln(n, 0);
    function<int(int,int)> cc_greedy = [&](int v, int p) {
        if (p == n - 1) return greedy_soln[p] = v;
        return (greedy_soln[p] = v / coins[p]) + cc_greedy(v % coins[p], p + 1);
    };

    function<int(int)> cc_dp = [&](int v) {
        if (v < 0) return int(1e9);
        if (v < sz(cc_dp_soln)) return cc_dp_soln[v];

        if (v >= sz(cc_dp_soln)) {
            cc_dp_soln.resize(v + 1, 1e9);
            cc_dp_parent.resize(v + 1, -1);
        }

        for (int i = 0; i < n; i++) {
            int res = cc_dp(v - coins[i]);
            if (1 + res < cc_dp_soln[v]) {
                cc_dp_soln[v] = 1 + res;
                cc_dp_parent[v] = i;
            }
        }

        return cc_dp_soln[v];
    };

    for (int i = 1; i < 1e9; i++) {
        int x = cc_greedy(i, 0), y = cc_dp(i);
        if (x != y) {
            cout << "Clash at " << i << "\n";
            
            cout << "Greedy: ";
            for (int i: greedy_soln) {
                cout << i << " ";
            } cout << "\n";

            cout << "DP    : ";
            vi hold(n, 0);
            int v = i;
            while (v > 0) {
                int p = cc_dp_parent[v];
                hold[p]++;
                v -= coins[p];
            }
            for (int i: hold) {
                cout << i << " ";
            } cout << "\n";
            return 0;
        }
    }
}