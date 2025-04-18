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

    ll n, H; cin >> n >> H;
    ll acc = 0;
    rep(i, 0, n) {
        vector<ll> dims(3);
        cin >> dims[0] >> dims[1] >> dims[2];
        sort(all(dims));
        if (H < dims[0]) {
            cout << "impossible\n";
            return 0;
        } else if (H < dims[1]) {
            // no choice, fit height as smallest
            acc += dims[1];
        } else {
            // safely pick smallest side as width
            acc += dims[0];
        }
    }
    cout << acc << "\n";
}