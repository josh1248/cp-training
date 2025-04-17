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

    vi n(3);
    rep(i, 0, 3) cin >> n[i];
    sort(all(n));

    int d1 = n[1] - n[0], d2 = n[2] - n[1];
    if (d1 == d2) {
        cout << d2 + n[2] << "\n";
    } else if (d1 == 2 * d2) {
        cout << n[0] + d2 << "\n";
    } else {
        cout << n[1] + d1 << "\n";
    }
}