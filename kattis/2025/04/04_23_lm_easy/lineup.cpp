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
    vector<string> x(n), y(n), z(n);
    rep(i, 0, n) {
        string a; cin >> a;
        x[i] = y[i] = z[i] = a;
    }
    sort(all(x));
    sort(all(z));
    reverse(all(z));
    bool inc = true, dec = true;
    rep(i, 0, n - 1) {
        if (x[i] != y[i]) inc = false;
        if (y[i] != z[i]) dec = false;
    }
    if (inc) cout << "INCREASING\n";
    else if (dec) cout << "DECREASING\n";
    else cout << "NEITHER\n";
}