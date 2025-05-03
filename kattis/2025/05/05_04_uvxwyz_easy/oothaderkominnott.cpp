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

    int i; cin >> i;
    if (i == 1) {
        int l; cin >> l;
        cout << l * l + 8 * (l - 1) << "\n";
    } else if (i == 2) {
        int l, w; cin >> l >> w;
        cout << 4 * (l - 1) + 4 * (w - 1) + l * w << "\n";
    } else {
        int l, w, h; cin >> l >> w >> h;
        cout << 2 * (l - 1) * (h - 1) + 2 * (w - 1) * (h - 1) + l * w << "\n";
    }
}