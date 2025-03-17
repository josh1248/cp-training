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
    ll N, M; cin >> N >> M;
    N -= 2; // must paint each color at leftmost and rightmost fence
    vector<ll> paints(M);
    rep(i, 0, M) {
        cin >> paints[i];
        paints[i]--; // use paint at leftmost and rightmost
        paints[i] = min(paints[i], N); // no need to use
    }
    sort(all(paints));
    vector<ll> suffixsums(M);
    ll total = 0;
    for (ll i = M - 1; i >= 0; i--) {
        total += paints[i];
        suffixsums[i] = total;
    }

    ll combis = 0;
    rep(i, 0, M - 1) {
        // find minimal index required on the right with binsearch s.t. x + y >= n
        ll x = paints[i];
        auto p = lower_bound(paints.begin() + i + 1, paints.end(), N - x);
        if (p == paints.end()) continue;
        // for each pairing of paints,
        // with paint volume x and y:
        // possible paints equal 2 * (x + y + 1 - n)
        // = 2 ( x + 1 - n) + 2 * y
        // thus, over a range:
        // 2 ((x + 1 - n) * (sz(range)) + sum(range))
        ll idx = distance(paints.begin(), p);
        combis += 2ll * ((x + 1 - N) * (M - idx) + suffixsums[idx]);
        // cout << i << " " << idx << " " << 2 * ((x + 1 - N) * (M - idx) + suffixsums[idx]) << "\n";
    }
    cout << combis << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}