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
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) {
        if (s[i] == "mumble") continue;
        int rep = stoi(s[i]) - 1;
        if (rep != i) {
            cout << "something is fishy\n";
            return 0;
        }
    }
    cout << "makes sense\n";
}