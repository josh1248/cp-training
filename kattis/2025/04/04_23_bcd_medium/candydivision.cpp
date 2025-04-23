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

    vector<ll> leftfactors, rightfactors;
    for (ll f = 1; f <= ll(round(pow(n, 0.5))) + 2ll; f++) {
        if (n % f == 0) {
            ll right = n / f;
            if (f <= right) {
                leftfactors.push_back(f);
            }
            if (f < right) {
                rightfactors.push_back(n / f);
            }      
        }
    }
    for (ll& i: leftfactors) cout << i - 1 << " ";
    reverse(all(rightfactors));
    for (ll& i: rightfactors) cout << i - 1 << " ";
}