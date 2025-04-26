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
    string flush; getline(cin, flush);
    rep(i, 0, n) {
        string s; getline(cin, s);
        vector<bool> hit(26, false);
        for (char c: s) {
            if (isalpha(c)) {
                hit[tolower(c) - 'a'] = true;
            }
        }

        if (all_of(all(hit), [](bool b){return b;})) {
            cout << "pangram\n";
        } else {
            cout << "missing ";
            rep(j, 0, 26) {
                if (!hit[j]) {
                    cout << char('a' + j);
                }
            }
            cout << "\n";
        }
    }
}