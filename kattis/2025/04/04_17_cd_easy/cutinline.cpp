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
    vector<string> q;
    rep(i, 0, n) {
        string s; cin >> s;
        q.push_back(s);
    }
    int x; cin >> x;
    rep(i, 0, x) {
        string action; cin >> action;
        if (action == "leave") {
            string toleave; cin >> toleave;
            rep(i, 0, sz(q)) {
                if (q[i] == toleave) {
                    q.erase(begin(q) + i);
                    break;
                }
            }
        } else {
            string a, b; cin >> a >> b;
            rep(i, 0, sz(q)) {
                if (q[i] == b) {
                    q.insert(begin(q) + i, a);
                    break;
                }
            }
        }
    }

    for (string s: q) cout << s << "\n";
}