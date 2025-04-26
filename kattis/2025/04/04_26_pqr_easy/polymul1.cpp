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

    int t; cin >> t;
    while (t--) {
        int a; cin >> a;
        vi p1(a + 1);
        rep(i, 0, a + 1) cin >> p1[i];
        int b; cin >> b;
        vi p2(b + 1);
        rep(i, 0, b + 1) cin >> p2[i];
        vi ans(a + b + 1);
        rep(i, 0, a + 1) {
            rep(j, 0, b + 1) {
                ans[i + j] += p1[i] * p2[j];
            }
        }
        cout << a + b << "\n";
        rep(i, 0, a + b + 1) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}