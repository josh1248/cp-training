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
    string a, b;
    a = s.substr(0, sz(s) / 2);
    b = s.substr(sz(s) / 2);
    int rotl = 0, rotr = 0;
    for (char c: a) {
        rotl += c - 'A';
    }
    for (char c: b) {
        rotr += c - 'A';
    }
    rep(i, 0, sz(a)) {
        cout << char('A' + (a[i] - 'A' + rotl + b[i] - 'A' + rotr) % 26);
    }
    cout << "\n";
    return 0;
}