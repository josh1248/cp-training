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

    ll acc = 0;
    int t; cin >> t;
    rep(i, 0, t) {
        string s; ll x; cin >> s >> x;
        acc += x;
    }
    if (acc < 0) cout << "Nekad\n";
    else if (acc > 0) cout << "Usch, vinst\n";
    else cout << "Lagom\n";
}