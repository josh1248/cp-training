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

    int d, r, t; cin >> d >> r >> t;
    rep(ageguess, 4, 999) {
        int expectedr = ageguess * (ageguess + 1) / 2 - 6;
        int expectedt = (ageguess - d) * (ageguess - d + 1) / 2 - 3;
        if (expectedr + expectedt == r + t) {
            cout << r - expectedr << "\n";
            return 0;
        }
    }
}