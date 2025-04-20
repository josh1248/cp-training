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
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    sort(all(v));
    if (n % 2 == 0) {
        int a = 0, b = 0;
        rep(i, 0, n) {
            if (i % 2 == 0) b += v[i];
            else a += v[i];
        }
        cout << a << " " << b << "\n";
    } else {
        int a = 0, b = 0;
        rep(i, 0, n) {
            if (i % 2 == 0) a += v[i];
            else b += v[i];
        }
        cout << a << " " << b << "\n";
    }
}