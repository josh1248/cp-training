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
    cout << n << ":\n";
    rep(base, 1, n / 2 + 1) {
        rep(first, 0, 2) {
            if (base + first == 1) continue;
            if (n % (2 * base + first) == 0 || n % (2 * base + first) == (base + first)) {
                cout << base + first << "," << base << "\n";
            }
        }
    }
}