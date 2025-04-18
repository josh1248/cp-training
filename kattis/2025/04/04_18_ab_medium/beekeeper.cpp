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

    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        int m = -1; string ans;
        rep(i, 0, n) {
            string s; cin >> s;
            int cnt = 0;
            rep(j, 0, sz(s) - 1) {
                if ((s[j] == s[j + 1]) && (
                    s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y'
                ))
                cnt++;
            }

            if (cnt > m) {
                m = cnt;
                ans = s;
            }
        }
        cout << ans << "\n";
    }
}