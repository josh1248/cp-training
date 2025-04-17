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

    string x; cin >> x;
    int t; cin >> t;
    rep(i, 0, t) {
        string s; cin >> s;
        rep(j, 0, sz(s)) {
            cout << char('A' + (s[j] - 'A') * (x[j] - '0') % 26);
        }
        cout << "\n";
    }
}