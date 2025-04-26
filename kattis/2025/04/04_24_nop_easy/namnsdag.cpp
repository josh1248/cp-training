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
    int n; cin >> n;
    rep(i, 0, n) {
        string x; cin >> x;
        if (sz(s) != sz(x)) continue;
        int hits = 0;
        rep(j, 0, sz(x)) {
            if (s[j] != x[j]) hits++;
        } 
        if (hits <= 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << n << "\n";
}