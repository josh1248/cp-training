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

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    int r;
    while (cin >> r) {
        if (r == 0) return 0;
        string s; cin >> s;
        reverse(all(s));
        for (char c: s) {
            int pos = -1;
            if (c >= 'A' && c <= 'Z') pos = c - 'A';
            else if (c == '_') pos = 26;
            else pos = 27;
            cout << alphabet[(pos + r) % 28];
        }
        cout << "\n";
    }

    vi cnts(256, 0);
    int record = 0;
    string s;
    rep(i, 0, 5) {
        cin >> s;
        cnts[s[0]]++;
        record = max(record, cnts[s[0]]);
    }
    cout << record << "\n";
}