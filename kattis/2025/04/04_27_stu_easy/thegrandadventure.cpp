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

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<char> inventory;
        bool ok = true;
        for (char c: s) {
            if (c == '$' || c == '|' || c == '*') inventory.push_back(c);
            else if (c == '.') continue;
            else if (sz(inventory) == 0) {
                ok = false;
                break;
            } else if (c == 't' && inventory.back() != '|') {
                ok = false;
            } else if (c == 'j' && inventory.back() != '*') {
                ok = false;
            } else if (c == 'b' && inventory.back() != '$') {
                ok = false;
            } else {
                inventory.pop_back();
            }
        }
        cout << ((ok && sz(inventory) == 0) ? "YES" : "NO") << "\n";
    }
}