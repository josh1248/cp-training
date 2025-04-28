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

    int acc = 0;
    int n; cin >> n;
    if (n <= 3) {
        cout << 0 << "\n";
        return 0;
    }
    n -= 2;
    rep(i, 1, n + 1) {
        // intersections with Vx to Vx+i edges
        acc += i * (n - i);
    }
    cout << acc * (n + 2) / 4 << "\n";
}