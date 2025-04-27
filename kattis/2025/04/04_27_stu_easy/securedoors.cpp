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

    unordered_set<string> ppl;
    int t; cin >> t;
    while (t--) {
        string cmd, s; cin >> cmd >> s;
        if (cmd == "entry") {
            cout << s << " entered ";
            if (ppl.count(s) > 0) {
                cout << "(ANOMALY)";
            } else {
                ppl.insert(s);
            }
            cout << "\n";
        } else {
            cout << s << " exited ";
            if (ppl.count(s) == 0) {
                cout << "(ANOMALY)";
            } else {
                ppl.erase(s);
            }
            cout << "\n";
        }
    }
}