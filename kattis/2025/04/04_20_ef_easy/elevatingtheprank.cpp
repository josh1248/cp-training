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

    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    int acc = 4 * (b - a);
    int q; cin >> q;
    rep(i, 0, q) {
        int x; cin >> x;
        if (x > a && x < b) acc += 10;
    }
    cout << acc << "\n";
}