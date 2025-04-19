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
    int a, b, h; cin >> a >> b >> h;
    if (h == 0) cout << 0 << "\n";
    else if (h <= a) cout << 1 << "\n";
    else {
        int nonfinal = h - a;
        cout << 1 + ceil(nonfinal * 1.0 / (a - b)) << "\n";
    }
}