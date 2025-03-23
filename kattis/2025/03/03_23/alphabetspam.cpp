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
    int whitespace = 0, lower = 0, upper = 0;
    for (char c: s) {
        if (isupper(c)) {
            upper++;
        } else if (islower(c)) {
            lower++;
        } else if (c == '_') {
            whitespace++;
        }
    }
    cout << double(whitespace) / sz(s) << "\n";
    cout << double(lower) / sz(s) << "\n";
    cout << double(upper) / sz(s) << "\n";
    cout << double(sz(s) - whitespace - lower - upper) / sz(s) << "\n";
}