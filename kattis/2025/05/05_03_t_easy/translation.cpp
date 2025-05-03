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
    vector<string> v(n);
    rep(i, 0, n) cin >> v[i];
    int q; cin >> q;
    unordered_map<string, string> dict;
    rep(i, 0, q) {
        string a, b; cin >> a >> b;
        dict[a] = b;
    }
    rep(i, 0, n) {
        cout << dict[v[i]] << " ";
    }
    cout << "\n";
    return 0;
}