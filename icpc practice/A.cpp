#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll R, C; cin >> R >> C;
    vector<string> grid(R);
    rep(i, 0, R) {
        cin >> grid[i];
    }

    vector<ull> row_sums(R), col_sums(C);
    rep(r, 0, R) {
        rep(c, 0, C) {
            if (grid[r][c] == '.') {
                row_sums[r]++;
                col_sums[c]++;
            }
        }
    }

    ull acc = 0;
    // case 1, straight rows
    rep(r, 0, R) {
        ull rsum = row_sums[r];
        if (rsum >= 4) {
            acc += rsum * (rsum - 1ull) * (rsum - 2ull) * (rsum - 3ull);
        }
    }
    // cout << acc << " ";

    // case 2, straight columns
    rep(c, 0, C) {
        ull csum = col_sums[c];
        if (csum >= 4) {
            acc += csum * (csum - 1ull) * (csum - 2ull) * (csum - 3ull);
        }
    }
    // cout << acc << " ";

    // case 3 + 4: h h v, or v h h
    rep(r, 0, R) {
        rep(c, 0, C) {
            // (r,c) is anchor
            // pick 2 others along row
            // pick along column
            if (grid[r][c] != '.') continue;
            ull rsum = row_sums[r], csum = col_sums[c];
            if (rsum < 3 || csum < 2) continue;
            acc += 2ull * (rsum - 1ll) * (rsum - 2ll) * (csum - 1ll);
        }
    }
    // cout << acc << " ";

    // case 5 + 6: v v h, or h v v
    rep(r, 0, R) {
        rep(c, 0, C) {
            if (grid[r][c] != '.') continue;
            ull rsum = row_sums[r], csum = col_sums[c];
            if (rsum < 2 || csum < 3) continue;
            acc += 2ull * (csum - 1ll) * (csum - 2ull) * (rsum - 1ull);
        }
    }
    // cout << acc << " ";

    // case 7: v h v
    // for each row, consider all columns with dot in that row
    // then pick second column
    rep(r, 0, R) {
        ull col_sums_filtered = 0;
        rep(c, 0, C) {
            if (grid[r][c] != '.') continue;
            col_sums_filtered += col_sums[c] - 1ull;
        }
        rep(c, 0, C) {
            if (grid[r][c] != '.') continue;
            // 3
            // 1 - 2
            //     4
            // twice for 4 1 - 2 3
            ull curr_col = col_sums[c] - 1ull;
            acc += (col_sums_filtered - curr_col) * (curr_col);
        }
    }
    // cout << acc << " ";

    // case 8: h v h
    rep(c, 0, C) {
        ull row_sums_filtered = 0;
        rep(r, 0, R) {
            if (grid[r][c] != '.') continue;
            row_sums_filtered += row_sums[r] - 1ull;
        }
        rep(r, 0, R) {
            if (grid[r][c] != '.') continue;
            // 1 2
            //   |
            //   3 4
            // twice
            ull curr_r = row_sums[r] - 1ull;
            acc += (row_sums_filtered - curr_r) * (curr_r);
        }
    }
    // cout << acc << " ";

    cout << acc << "\n";

}