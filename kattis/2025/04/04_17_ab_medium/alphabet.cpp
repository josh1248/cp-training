#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

vvi dp;
string s;

int memo(int idx, int fulfilled) {
    if (idx >= sz(s)) return 26 - fulfilled;
    else if (fulfilled == 26) return 0;
    int& ans = dp[idx][fulfilled];
    if (ans != -1) return ans;
    else if (s[idx] - 'a' == fulfilled) {
        return ans = memo(idx + 1, fulfilled + 1);
    } else {
        return ans = min(1 + memo(idx, fulfilled + 1), memo(idx + 1, fulfilled));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    dp = vvi(sz(s), vi(26, -1));
    cout << memo(0, 0) << "\n";
}