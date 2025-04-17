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
    vector<string> ins; string s;
    while (cin >> s) {
        ins.push_back(s);
    }

    vector<string> ans;
    rep(i, 1, sz(ins)) {
        bool marked = false;
        for (char c: ins[0]) {
            if (ins[i].find(c) != string::npos) {
                marked = true;
                break;
            }
        }
        if (marked) {
            string x(sz(ins[i]), '*');
            ans.push_back(x);
        } else {
            ans.push_back(ins[i]);
        }
    }

    cout << ans[0];
    rep(i, 1, sz(ans)) {
        cout << " " << ans[i];
    }
    cout << "\n";
    return 0;
}