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

    string s; cin >> s;
    if (sz(s) == 10) {
        cout << -1 << "\n";
        return 0;
    }
    int curr = 1;
    rep(i, 0, min(9, sz(s))) {
        if (s[i] == (curr + '0')) {
            curr++;
        } else {
            cout << -1;
            return 0;
        }
    }
    cout << curr - 1 << "\n";
    return 0;
}