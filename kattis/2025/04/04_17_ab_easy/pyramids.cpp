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
    ll h = 1;
    ll used = 0;
    while (used < n) {
        ll base = 2 * h - 1;
        used += (base * base);
        if (used > n) break;
        h++;
    }
    cout << h - 1 << "\n";
}