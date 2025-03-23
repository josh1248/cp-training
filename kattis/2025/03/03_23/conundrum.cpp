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
    int h = 0;
    rep(i, 0, sz(s)) {
        if (i % 3 == 0 && s[i] != 'P') {
            h++;
        } else if (i % 3 == 1 && s[i] != 'E') {
            h++;
        } else if (i % 3 == 2 && s[i] != 'R') {
            h++;
        }
    }
    cout << h << "\n";
}