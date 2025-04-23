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

    int n, lph; cin >> n >> lph;
    lph *= 5;
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    sort(all(v));
    int acc = 0;
    rep(i, 0, n) {
        if (acc + v[i] > lph) {
            cout << i << "\n";
            return 0;
        }
        acc += v[i];
    }
    cout << n << "\n";
}