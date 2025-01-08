#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
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
    cin.tie(NULL);
    int n;
    cin >> n;
    int t_count = ((1LL << (2 * n)) - 1) / 3;
    vvi grid((1LL << n) + 2, vi((1LL << n) + 2, -1)); // buffer of -1 
    vi counts(t_count + 1, 0); // 3 tiles per tetromino
    vector<bool> shapes(t_count + 1, false); // must have L-shape

    int m;
    for (int i = 1; i <= (1LL << n); i++) {
        for (int j = 1; j <= (1LL << n); j++) {
            cin >> m;
            if (m < 0 || m > t_count) {
                cout << 0 << "\n";
                return 0;
            }
            counts[m]++;
            // if count is not balanced, counts[m] > 3 or OOB will eventually be triggered
            if ((m == 0 && counts[m] > 1) || (counts[m] > 3)) {
                cout << 0 << "\n";
                return 0;
            }
            grid[i][j] = m;
        }
    }

    if (!all_of(counts.begin() + 1, counts.end(), [](int i) { return i == 3; })) {
        cout << 0 << "\n";
        return 0;
    }

    vector<pi> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W, N;

    for (int i = 1; i <= (1 << n); i++) {
        for (int j = 1; j <= (1 << n); j++) {
            for (int k = 0; k < 4; k++) {
                auto [r1, c1] = dirs[k];
                auto [r2, c2] = dirs[k + 1];
                if (grid[i][j] == grid[i + r1][j + c1] && grid[i][j] == grid[i + r2][j + c2]) {
                    shapes[grid[i][j]] = true;
                }
            }
        }
    }

    cout << (all_of(shapes.begin() + 1, shapes.end(), [](bool b){ return b; }) ? 1 : 0) << "\n"; 
}