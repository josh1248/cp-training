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

    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) return 0;
        else if (x + y == 13) cout << "Never speak again.\n";
        else if (x > y) cout << "To the convention.\n";
        else if (x < y) cout << "Left beehind.\n";
        else cout << "Undecided.\n";
    }
}