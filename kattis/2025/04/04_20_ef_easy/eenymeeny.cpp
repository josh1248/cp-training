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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    string s; getline(cin, s);
    int reps = 1;
    for (char c: s) if (c == ' ') reps++;
    int n; cin >> n;
    vector<string> names(n);
    rep(i, 0, n) cin >> names[i];
    vector<string> left, right;
    int offset = 0;
    bool flip = true;

    rep(i, 0, n) {
        int target = ((reps - 1 + offset) % sz(names));
        if (flip) left.push_back(names[target]);
        else right.push_back(names[target]);
        flip = !flip;
        names.erase(begin(names) + target);
        offset = target;
    }

    cout << sz(left) << "\n";
    for (string x: left) cout << x << "\n";
    cout << sz(right) << "\n";
    for (string x: right) cout << x << "\n";
}