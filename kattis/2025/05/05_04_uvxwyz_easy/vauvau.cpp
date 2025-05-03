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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vi v(3);
    rep(i, 0, 3) cin >> v[i];
    rep(i, 0, 3) {
        v[i]--;
        int hit = 0;
        if (v[i] % (a + b) < a) hit++;
        if (v[i] % (c + d) < c) hit++;
        if (hit == 2) {
            cout << "both\n";
        } else if (hit == 1) {
            cout << "one\n";
        } else {
            cout << "none\n";
        }
    }
}