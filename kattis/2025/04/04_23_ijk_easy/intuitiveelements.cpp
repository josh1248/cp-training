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
        vector<bool> hit(26, false);
        string s; cin >> s;
        for (char c: s) hit[c - 'a'] = true;
        string test; cin >> test;
        bool ok = true;
        for (char c: test) {
            if (!hit[c - 'a']) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}