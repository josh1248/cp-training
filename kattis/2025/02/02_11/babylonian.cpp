#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        s += ",";
        ll ans = 0;
        string acc = "";
        for (char c: s) {
            if (c == ',') {
                ans *= 60;
                ans += stoi(sz(acc) ? acc : "0");
                acc = "";
            } else {
                acc += c;
            }
        }
        cout << ans << "\n";
    }
}