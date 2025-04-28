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
    int x = 1;
    while (cin >> n) {
        if (n == 0) return 0;
        cout << "SET " << x++ << "\n";
        bool t = true;
        vector<string> left, right;
        rep(i, 0, n) {
            string s; cin >> s;
            if (t) left.push_back(s);
            else right.push_back(s);
            t = !t;
        }
        reverse(all(right));
        for (string s: left) cout << s << "\n";
        for (string s: right) cout << s << "\n";
    }
}