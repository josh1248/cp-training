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
    vector<char> opts(n);
    rep(i, 0, n) cin >> opts[i];
    ll acc = 0;
    rep(i, 1, n) {
        if (opts[i] == opts[i - 1]) acc++;
    }
    cout << acc << "\n";
}