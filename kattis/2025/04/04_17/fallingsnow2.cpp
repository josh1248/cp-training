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
    vi cnts(C, 0);
    vector<string> s(R);
    rep(i, 0, R) cin >> s[i];
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (s[i][j] == 'S') cnts[j]++;
        }
    }

    rep(i, 0, R) {
        rep(j, 0, C) {
            cout << ((i >= R - cnts[j]) ? 'S' : '.');
        }
        cout << "\n";
    }
}