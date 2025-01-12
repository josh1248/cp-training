#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef long long ll;
typedef priority_queue<int, vi, greater<int>> minpq;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;

        vector<vll> grid(n, vll(m, 0));
        vi row_sums(n, 0), col_sums(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k; cin >> k;
                grid[i][j] = k;
                row_sums[i] += k;
                col_sums[j] += k;
            }
        }


        // find that x = 0 is always the solution.
        // n * x = m * x (total sum across rows and total sum across columns)
        // x = 0 is only possible solution for non-square, and infinite possible solutions for square.
        // additionally, since there will always exist a row or column with a single blank cell,
        // we can fill this matrix to give a solution.
        ll x = 0;

        int r = 0, c = 0;
        for (char dir: s) {
            if (dir == 'D') {
                // fill by row
                grid[r][c] = -row_sums[r];
                col_sums[c] -= row_sums[r];
                r++;
                row_sums[r] = 0;
            } else {
                // fill by column
                grid[r][c] = -col_sums[c];
                row_sums[r] -= col_sums[c];
                c++;
                col_sums[c] = 0;    
            }
        }

        grid[n - 1][m - 1] = -row_sums[n - 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
}