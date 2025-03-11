#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll n, x, k;
        string s;
        cin >> n >> x >> k >> s;
        int i = 0;
        for (int curr = x; i < sz(s); i++) {
            char c = s[i];
            if (c == 'L') {
                curr--;
            } else {
                curr++;
            }

            if (curr == 0) {
                break;
            }
        }

        int j = 0;
        for (int curr = 0; j < sz(s); j++) {
            char c = s[j];
            if (c == 'L') {
                curr--;
            } else {
                curr++;
            }

            if (curr == 0) {
                break;
            }
        }

        if (i == sz(s)) {
            // never ever reaches 0
            cout << 0 << "\n";
        } else if (j == sz(s)) {
            // touches 0 once and goes off
            cout << 1 << "\n";
        } else {
            // touch 0 in i + 1 steps, then repeats every j + 1 steps
            k -= (i + 1);
            cout << 1 + (k / (j + 1)) << "\n";
        }
    }
}