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
    vi val(45), denom(45);
    rep(i, 0, n) {
        string s; cin >> s;
        rep(j, 0, sz(s)) {
            denom[j]++;
            val[j] += s[j];
        }
    }
    rep(i, 0, 45) {
        if (denom[i] == 0) break;
        cout << char(val[i] / denom[i]);
    }
    cout << "\n";
}