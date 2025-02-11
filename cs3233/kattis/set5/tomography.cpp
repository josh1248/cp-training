#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int R, C; cin >> R >> C;
    vi row_req(R);
    priority_queue<pi> col_req;
    for (int i = 0; i < R; i++) {
        cin >> row_req[i];
    }
    for (int i = 0; i < C; i++) {
        int x; cin >> x;
        if (x > 0) col_req.emplace(x, i);
    }
    vector<vector<bool>> grid(R, vector<bool>(C, false));

    // greedy alloc row squares, and to col with largest requirement
    for (int i = 0; i < R; i++) {
        vector<pi> used;
        for (int j = 0; j < C; j++) {
            if (row_req[i] > 0 && sz(col_req) > 0) {
                // cannot put & here!!! (rmb heap stuff)
                auto [cnt, col] = col_req.top();
                grid[i][col] = true;
                col_req.pop();
                if (cnt > 1) {
                    used.emplace_back(cnt - 1, col);
                }
                row_req[i]--;
            }
        }
        for (auto& [k, v]: used) {
            col_req.emplace(k, v);
        }
    }
    auto nz = [](int x){ return x != 0; };
    if (any_of(all(row_req), nz) || sz(col_req) > 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    // cout << "Final alloc:\n";
    // for (auto& r: grid) {
    //     for (bool c: r) {
    //         cout << c;
    //     }
    //     cout << "\n";
    // }
    return 0;
}