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

    string s; getline(cin, s);
    reverse(all(s));
    if (sz(s) % 3 > 0) s.append(3 - sz(s) % 3, '0');
    reverse(all(s));
    rep(i, 0, sz(s) / 3) {
        int x = 0;
        rep(j, 0, 3) {
            x *= 2;
            x += s[3 * i + j] - '0';
        }
        cout << x;
    }
    cout << "\n";
}