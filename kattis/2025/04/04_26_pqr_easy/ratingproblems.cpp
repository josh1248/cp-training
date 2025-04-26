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

    int n, k; cin >> n >> k;
    cout << setprecision(6) << fixed;
    int acc = 0;
    rep(i, 0, k) {
        int x; cin >> x;
        acc += x;
    }
    cout << 1.0 * (acc - 3 * (n - k)) / n << " "
        << 1.0 * (acc + 3 * (n - k)) / n << "\n";
}