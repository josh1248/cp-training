#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, s, k; cin >> r >> s >> k;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    vvi rsq(r + 1, vi(s + 1, 0));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= s; j++) {
            rsq[i][j] = rsq[i - 1][j] + rsq[i][j - 1] - rsq[i - 1][j - 1];
            rsq[i][j] += (grid[i-1][j-1] == '*' ? 1 : 0);
        }
    }

    pi topleft; int maxSoFar = -1;
    for (int i = 1; i <= r - k + 1; i++) {
        for (int j = 1; j <= s - k + 1; j++) {
            int query = rsq[i + k - 2][j + k - 2] - rsq[i][j + k - 2] - rsq[i + k - 2][j] + rsq[i][j];
            if (query > maxSoFar) {
                maxSoFar = query;
                topleft = {i, j};
            }
        }
    }

    auto [x, y] = topleft; x--; y--;
    for (int i = 1; i < k - 1; i++) {
        grid[x + i][y] = '|';
        grid[x + i][y + k - 1] = '|';
        grid[x][y + i] = '-';
        grid[x + k - 1][y + i] = '-';
    }

    grid[x][y] = grid[x+k-1][y] = grid[x][y+k-1] = grid[x+k-1][y+k-1] = '+';
    cout << maxSoFar << "\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}