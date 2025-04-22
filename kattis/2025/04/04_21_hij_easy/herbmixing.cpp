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

    int g, r; cin >> g >> r;
    if (g <= r) {
        cout << 10 * g << "\n";
    } else {
        ll acc = 0;
        acc += 10 * min(g, r);
        g -= r;
        acc += 10 * (g / 3);
        g = g % 3;
        if (g == 1) acc++;
        else if (g == 2) acc += 3;
        cout << acc << "\n";
    }
}