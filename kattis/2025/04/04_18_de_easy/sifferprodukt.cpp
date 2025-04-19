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

    int x; cin >> x;
    while (true) {
        string s = to_string(x);
        if (sz(s) == 1) {
            cout << s << "\n";
            return 0;
        }
        ll mult = 1;
        for (char c: s) {
            if (c == '0') continue;
            mult *= (c - '0');
        }
        x = mult;
    }
}