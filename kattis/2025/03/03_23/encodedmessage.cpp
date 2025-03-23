#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int grid_size;
pair<int, int> pos_to_grid(int p) {return {p / grid_size, p % grid_size};}
int grid_to_pos(int r, int c) {return r * grid_size + c;}
int f_inv(int p) {
    auto [i, j] = pos_to_grid(p);
    return grid_to_pos(grid_size - 1 - j, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        grid_size = round(pow(s.size(), 0.5));
        string out(s.size(), '.');
        for (int p = 0; p < s.size(); p++) {
            out[f_inv(p)] = s[p];
        }
        cout << out << "\n";
    }
}