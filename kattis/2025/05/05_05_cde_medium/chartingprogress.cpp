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

    int colsz = -1, placed = -1;
    string s;
    while(getline(cin, s)) {
        if (s == "") {
            colsz = -1, placed = -1;
            cout << "\n";
            continue;
        }
        if (colsz == -1 && placed == -1) {
            colsz = sz(s), placed = 0;
        }
        int cnt = 0;
        for (char c: s) {
            if (c == '*') cnt++;
        }
        string out(colsz, '.');
        rep(i, placed, placed + cnt) {
            out[sz(out) - 1 - i] = '*';
        }
        placed += cnt;
        cout << out << "\n";
    }
}