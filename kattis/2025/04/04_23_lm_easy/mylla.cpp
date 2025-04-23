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

    vector<string> grid(3);
    rep(i, 0, 3) cin >> grid[i];
    vector<bool> O(9, false);
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            if (grid[i][j] == 'O') {
                O[3 * i + j] = true;
            }
        }
    }

    if ((O[0] && O[3] && O[6]) ||
        (O[1] && O[4] && O[7]) ||
        (O[2] && O[5] && O[8]) || 
        (O[0] && O[1] && O[2]) ||
        (O[3] && O[4] && O[5]) ||
        (O[6] && O[7] && O[8]) ||
        (O[0] && O[4] && O[8]) ||
        (O[2] && O[4] && O[6])) {
            cout << "Jebb\n";
            return 0;
    }
    else cout << "Neibb\n";
}