#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    int grid[n][n];
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < n - 1; i++) {
        grid[i][i] = 3 * i + 3;
        grid[i][i+1] = 3 * i + 4;
        grid[i+1][i] = 3 * i + 2;
    }
    grid[n-1][n-1] = 1;
    int s = 3 * (n - 1) + 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                cout << grid[i][j] << " "; continue;
            }
            cout << s++ << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}