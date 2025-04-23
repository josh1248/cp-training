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

    string x, y; cin >> x >> y;
    vi pos(26, -1);
    rep(j, 0, sz(y)) {
        if (pos[y[j] - 'A'] == -1) pos[y[j] - 'A'] = j;
    } 
    int xhit = 0, yhit = 0;
    vector<string> grid(sz(y), string(sz(x), '.'));
    rep(i, 0, sz(x)) {
        if (pos[x[i] - 'A'] != -1) {
            yhit = pos[x[i] - 'A'], xhit = i;
            break;
        }
    }
    rep(i, 0, sz(y)) {
        grid[i][xhit] = y[i];
    }
    rep(i, 0, sz(x)) {
        grid[yhit][i] = x[i];
    }
    for (string x: grid) cout << x << "\n";
}