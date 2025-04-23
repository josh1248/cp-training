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
    string xs, ys;
    for (char c: s) {
        if (c == '0') {
            xs.append("0");
            ys.append("0");
        } else if (c == '1') {
            xs.append("1");
            ys.append("0");
        } else if (c == '2') {
            xs.append("0");
            ys.append("1");
        } else {
            xs.append("1");
            ys.append("1");
        }
    }
    ll x = 0;
    for (char c: xs) {
        x *= 2;
        x += c - '0';
    }
    ll y = 0;
    for (char c: ys) {
        y *= 2;
        y += c - '0';
    }
    cout << sz(s) << " " << x << " " << y << "\n";
}