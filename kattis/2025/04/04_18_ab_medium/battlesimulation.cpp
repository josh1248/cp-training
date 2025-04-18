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
    int curr = 0;
    string res;
    while (curr < sz(s)) {
        if (curr + 2 < sz(s)) {
            string check = s.substr(curr, 3);
            if (check.find("R") != string::npos &&
                check.find("L") != string::npos &&
                check.find("B") != string::npos) {
                res.append("C");
                curr += 3;
                continue;
            }
        }

        if (s[curr] == 'R') res.append("S");
        else if (s[curr] == 'L') res.append("H");
        else res.append("K");
        curr++;
    }
    cout << res << "\n";
}