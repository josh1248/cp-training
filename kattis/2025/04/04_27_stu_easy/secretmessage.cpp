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

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int sq = ceil(pow(sz(s), 0.5));
        vector<vector<char>> grid(sq, vector<char>(sq, '*'));
        rep(i, 0, sz(s)) {
            grid[i / sq][i % sq] = s[i];
        }
        rep(j, 0, sq) {
            for (int i = sq - 1; i >= 0; i--) {
                if (grid[i][j] == '*') continue;
                cout << grid[i][j];
            }
        }
        cout << "\n";
    }
}