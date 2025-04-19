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
    vi cities(n);
    rep(i, 0, n) cin >> cities[i];
    sort(all(cities), greater<int>());
    ll total = 0;
    rep(i, 0, sz(cities) / 2) total += cities[i];
    rep(i, sz(cities) / 2, sz(cities)) total += cities[i] / 2;
    cout << total << "\n";
}