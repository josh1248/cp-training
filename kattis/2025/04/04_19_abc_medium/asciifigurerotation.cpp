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

    int R; string flush;
    bool first = true;
    while (cin >> R) {
        if (R == 0) {
            cout << "\n";
            return 0;
        }
        if (first) {
            first = false;
        } else {
            cout << "\n\n";
        }
        getline(cin, flush);
        int longestline = 0;
        vector<string> ins(R);
        rep(i, 0, R) {
            getline(cin, ins[i]);
            longestline = max(longestline, sz(ins[i]));
        }


        vi non_space_highest(longestline, 0);
        rep(i, 0, R) {
            rep(j, 0, sz(ins[i])) {
                if (ins[i][j] == ' ') continue;
                non_space_highest[j] = max(non_space_highest[j], R - i);
            }
        }

        rep(i, 0, longestline) {
            rep(j, 0, non_space_highest[i]) {
                int ctarget = i;
                int rtarget = R - j - 1;
                char x = ins[rtarget][ctarget];
                // cout << rtarget << " " << ctarget << "\n";
                if (ctarget >= sz(ins[rtarget])) cout << ' ';
                else if (x == ' ') cout << x;
                else if (x == '+') cout << x;
                else if (x == '|') cout << '-';
                else cout << '|';
            }
            if (i != longestline - 1) cout << "\n";
        }
    }
}