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
    rep(i, 0, sz(s)) {
        if (i + 1 < sz(s)) {
            if (s.substr(i, 2) == ":)" || s.substr(i, 2) == ";)") {
                cout << i << "\n";
            }
        }
        if (i + 2 < sz(s)) {
            if (s.substr(i, 3) == ":-)" || s.substr(i, 3) == ";-)") {
                cout << i << "\n";
            }
        }
    }
}