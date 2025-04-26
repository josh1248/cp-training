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

    int R, C; cin >> R >> C;
    vector<string> grid(R);
    rep(i, 0, R) cin >> grid[i];
    ll acc = 0;
    rep(i, 0, R) {
        rep(j, 0, C) {
            switch (grid[i][j]) {
            case '.': acc += 20; break;
            case 'O': acc += 10; break;
            case '\\': acc += 25; break;
            case '/': acc += 25; break;
            case 'A': acc += 35; break;
            case '^': acc += 5; break;
            case 'v': acc += 22; break;
            }
        }
    }
    cout << acc << "\n";
}