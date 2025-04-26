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

    char op; string s; cin >> op >> s;
    if (op == 'E') {
        char curr = s[0];
        int cnt = 1;
        string res;
        rep(i, 1, sz(s)) {
            if (s[i] == curr) cnt++;
            else {
                res.append(1, curr);
                res.append(to_string(cnt));
                curr = s[i];
                cnt = 1;
            }
        }
        res.append(1, curr);
        res.append(to_string(cnt));
        cout << res << "\n";
    } else {
        string res;
        rep(i, 0, sz(s) / 2) {
            res.append(stoi(string(1, s[2 * i + 1])), s[2 * i]);
        }
        cout << res << "\n";
    }
}