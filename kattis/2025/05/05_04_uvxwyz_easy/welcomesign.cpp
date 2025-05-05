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

    int r, c; cin >> r >> c;
    bool flip = false;
    rep(i, 1, r + 1) {
        string s; cin >> s;
        int cut = (c - sz(s)) / 2;
        int remaining = (c - sz(s)) % 2;
        if (remaining != 0) flip = !flip;
        string l(cut + (remaining && !flip), '.'),
            r(cut + (remaining && flip), '.');
        
        cout << l << s << r << "\n";
    }
}