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
    int x  = sz(s);
    if (x % 2 != 0) {
        cout << "fix\n";
        return 0;
    } else {
        rep(i, 0, sz(s) / 2 - 1) {
            if (s[i] != '|') {
                cout << "fix\n";
                return 0;
            }
        }
        if (s[sz(s) / 2 - 1] != '(') {
            cout << "fix\n";
            return 0;
        }
        if (s[sz(s) / 2] != ')') {
            cout << "fix\n";
            return 0;
        }
        rep(i, sz(s) / 2 + 1, sz(s)) {
            if (s[i] != '|') {
                cout << "fix\n";
                return 0;
            }
        }
        cout << "correct\n";
    }
}