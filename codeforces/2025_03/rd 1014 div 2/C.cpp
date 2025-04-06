#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

void solve() {
    int N; cin >> N;
    vector<ll> odds, evens;
    ll x;
    rep(i, 0, N) {
        cin >> x;
        if (x % 2 == 0) evens.push_back(x);
        else odds.push_back(x);
    }

    ll oddsum = accumulate(all(odds), 0ll), evensum = accumulate(all(evens), 0ll);
    sort(all(odds));
    sort(all(evens));
    if (sz(evens) == 0) {
        cout << *odds.rbegin() << "\n";
    } else if (sz(odds) == 0) {
        cout << *evens.rbegin() << "\n";
    } else {
        // absorb all odd values to evens, end at 1 odd tower
        // (1 remaining for each odd tower except last)
        ll endeven_remaining = sz(odds) - 1;
        cout << oddsum + evensum - endeven_remaining << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}