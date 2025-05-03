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
    int word = sz(s) / 3;
    vvi best(word, vi(26, 0));
    rep(i, 0, word) {
        rep(j, 0, 3) {
            best[i][s[j * word + i] - 'a']++;
        }
    }
    string out(word, '.');
    rep(i, 0, word) {
        rep(j, 0, 26) {
            if (best[i][j] >= 2) out[i] = j + 'a';
        }
    }
    cout << out << "\n";
}