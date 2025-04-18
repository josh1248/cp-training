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
    vi res(n);
    rep(i, 0, n) cin >> res[i];
    sort(all(res));
    do {
        bool ok = true;
        rep(i, 0, n - 1) {
            if (gcd(res[i], res[i + 1]) == 1) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int i: res) cout << " " << i;
            return 0;
        }
    } while (next_permutation(all(res)));
    cout << "Neibb\n";
}