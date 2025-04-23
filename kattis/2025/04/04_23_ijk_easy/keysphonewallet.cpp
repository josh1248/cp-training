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

    bool k = false, p = false, w = false;
    int n; cin >> n;
    rep(i, 0, n) {
        string s; cin >> s;
        if (s == "keys") k = true;
        if (s == "phone") p = true;
        if (s == "wallet") w = true;
    }

    if (!k) cout << "keys\n";
    if (!p) cout << "phone\n";
    if (!w) cout << "wallet\n";
    if (k && p && w) cout << "ready\n";
}