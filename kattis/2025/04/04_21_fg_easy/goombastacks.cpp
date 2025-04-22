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

    ll n; cin >> n;
    ll curr = 0;
    rep(i, 0, n) {
        ll a, b; cin >> a >> b;
        curr += a;
        if (curr < b) {
            cout << "impossible\n";
            return 0;
        }
    }
    cout << "possible\n";
}