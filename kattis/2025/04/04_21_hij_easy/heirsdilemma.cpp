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

    ll lo, hi; cin >> lo >> hi;
    ll acc = 0;
    rep(i, lo, hi + 1) {
        string s = to_string(i);
        bool possible = true;
        set<int> seen;
        for (char c: s) {
            if (c == '0') possible = false;
            else if (i % (c - '0') != 0) possible = false;
            else if (seen.count(c) > 0) possible = false;
            seen.insert(c);
        }
        if (possible) acc++;
    }
    cout << acc << "\n";
}