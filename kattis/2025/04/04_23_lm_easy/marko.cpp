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

    int n; cin >> n;
    vector<string> words(n);
    rep(i, 0, n) cin >> words[i];
    string s; cin >> s;
    int acc = 0;
    rep(i, 0, n) {
        bool ok = true;
        rep(j, 0, sz(words[i])) {
            if (sz(words[i]) != sz(s)) {
                ok = false;
                break;
            }
            int p;
            switch (words[i][j] - 'a') {
            case 0: case 1: case 2:
                p = 2; break;
            case 3: case 4: case 5:
                p = 3; break;
            case 6: case 7: case 8:
                p = 4; break;
            case 9: case 10: case 11:
                p = 5; break;
            case 12: case 13: case 14:
                p = 6; break;
            case 15: case 16: case 17: case 18:
                p = 7; break;
            case 19: case 20: case 21:
                p = 8; break;
            case 22: case 23: case 24: case 25:
                p = 9; break;
            }
            if ((p + '0') != s[j]) ok = false;
        }
        if (ok) acc++;
    }
    cout << acc << "\n";
}