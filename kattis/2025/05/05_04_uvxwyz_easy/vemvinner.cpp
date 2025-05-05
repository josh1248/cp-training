#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vvi wins = {
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,4,8},
    {2,4,6}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> grid(9, '.');
    rep(i, 0, 9) cin >> grid[i];

    for (auto& v: wins) {
        if (grid[v[0]] == 'X' && grid[v[1]] == 'X' && grid[v[2]] == 'X') {
            cout << "Johan har vunnit\n";
            return 0;
        } else if (grid[v[0]] == 'O' && grid[v[1]] == 'O' && grid[v[2]] == 'O') {
            cout << "Abdullah har vunnit\n";
            return 0;
        }
    }
    cout << "ingen har vunnit\n";
}