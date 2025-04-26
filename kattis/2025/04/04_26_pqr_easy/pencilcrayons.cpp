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

    int r, c; cin >> r >> c;
    int acc = 0;
    rep(i, 0, r) {
        unordered_set<string> seen;
        rep(i, 0, c) {
            string s; cin >> s;
            if (seen.count(s) > 0) {
                acc++;
            } else {
                seen.insert(s);
            }
        }
    }
    cout << acc << "\n";
}