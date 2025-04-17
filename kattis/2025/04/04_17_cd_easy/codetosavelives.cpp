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
    string x, y; ll a, b;
    getline(cin, x);
    while (t--) {
        getline(cin, x);
        getline(cin, y);
        a = 0, b = 0;
        for (int i = 0; i < sz(x); i += 2) {
            a *= 10;
            a += (x[i] - '0');
        }
        for (int i = 0; i < sz(y); i += 2) {
            b *= 10;
            b += (y[i] - '0');
        }
        ll res = a + b;
        string z = to_string(res);
        for (char c: z) cout << c << " ";
        cout << "\n";
    }
}