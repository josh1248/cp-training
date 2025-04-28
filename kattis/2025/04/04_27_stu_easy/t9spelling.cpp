#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vector<string> opts = {
    "2","22","222",
    "3","33","333",
    "4","44","444",
    "5","55","555",
    "6","66","666",
    "7","77","777","7777",
    "8","88","888",
    "9","99","999","9999"
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string flush;
    int t; cin >> t; getline(cin, flush);
    rep(i, 0, t) {
        cout << "Case #" << i + 1 << ": ";
        string s; getline(cin, s);
        char prev = 'X';
        for (char c: s) {
            string o;
            if (c == ' ') {
                o = "0";
                if (o[0] == prev) cout << ' ';
                prev = o[0];
                cout << o;
            } else {
                o = opts[c - 'a'];
                if (o[0] == prev) cout << ' '; 
                prev = o[0];
                cout << o;
            }
        }
        cout << "\n";
    }
}