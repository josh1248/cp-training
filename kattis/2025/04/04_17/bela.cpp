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
    int n; char trump; cin >> n >> trump;
    int total = 0;
    rep(i, 0, 4 * n) {
        string s; cin >> s;
        if (s[1] == trump) {
            if (s[0] == 'A') total += 11;
            else if (s[0] == 'K') total += 4;
            else if (s[0] == 'Q') total += 3;
            else if (s[0] == 'J') total += 20;
            else if (s[0] == 'T') total += 10;
            else if (s[0] == '9') total += 14;
        } else {
            if (s[0] == 'A') total += 11;
            else if (s[0] == 'K') total += 4;
            else if (s[0] == 'Q') total += 3;
            else if (s[0] == 'J') total += 2;
            else if (s[0] == 'T') total += 10;
        }
    }
    cout << total << "\n";
}