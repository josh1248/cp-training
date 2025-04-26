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

    int n, m; cin >> n >> m;
    vector<bool> hit(m + 1, false);
    hit[0] = true;
    rep(i, 0, n) {
        int x; cin >> x;
        rep(j, 0, x) {
            int piece; cin >> piece;
            hit[piece] = true;
        }
    }

    if (all_of(all(hit), [](bool b){return b;})) {
        cout << "Jebb\n";
    } else {
        cout << "Neibb\n";
    }
}