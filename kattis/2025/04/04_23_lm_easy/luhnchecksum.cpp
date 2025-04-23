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
    while (n--) {
        string s; cin >> s;
        reverse(all(s));
        int checksum = 0;
        rep(i, 0, sz(s)) {
            if (i % 2 == 1) {
                int x = 2 * (s[i] - '0');
                checksum += (x % 10 + x / 10);
            } else {
                checksum += s[i] - '0';
            }
        }
        cout << (checksum % 10 == 0 ? "PASS" : "FAIL") << "\n";
    }
}