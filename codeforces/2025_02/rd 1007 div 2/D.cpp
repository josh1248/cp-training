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
    ll n, l, r; cin >> n >> l >> r;
    vi arr(n + 1, 0);
    vector<bool> parities(n + 1, false);
    bool is_even = true;
    // equivalent: solve the sum mod 2
    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        if (b == 1) {
            is_even = !is_even;
        }
        arr[i] = b;
        parities[i] = is_even;
    }

    // if n is even, cant cancel cleanly
    // a_n+1 a_n+2 .... , then a_n+1 cannot cancel
    // just insert 1 more element to make it odd again
    if (n % 2 == 0) {
        bool b = parities[n / 2];
        arr.emplace_back(b ? 0 : 1);
        if (!b) {
            is_even = !is_even;
        }
        parities.emplace_back(is_even);
        n++;
    }

    // idea: beyond pre-generated array,
    // we can ignore the sum of pairs a_k and a_k+1
    // if full cancel, return parities[i]
    // else, recurse;
    ll curr = l;
    while (curr > n) {
        // cout << curr << " ";
        ll nxt = (curr / 2ll);
        if (nxt <= n) {
            curr = nxt;
            break;
        } else if ((nxt - n) % 2 == 0) {
            curr = n;
            break;
        } else {
            curr = nxt;
        }
    }

    cout << (parities[curr] ? 0 : 1) << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    // vi test = {999, 0, 0, 1, 0, 0, 0};
    // // vi test = {999, 1, 1, 0, 0};
    // // vi test = {999, 1 , 0};
    // rep(i, 6, 3000) {
    //     int acc = 0;
    //     rep(j, 1, 1 + (i / 2)) {
    //         acc ^= test[j];
    //     }
    //     test.emplace_back(acc);
    // }

    // rep(i, 0, sz(test)) {
    //     cout << test[i] << " ";
    // }
    // cout << "\n";

    // cout << "Guess: ";
    // unordered_map<int, int> cache;
    // function<int(int)> guess = [&](int i) {
    //     if (i < sz(test)) return test[i];
    //     if (cache.count(i) > 0) return cache[i];
    //     else if (i % 2 == 1)
    // }

    // rep(r, 1, 5) {
    //     cout << r << ": ";
    //     for (int i = r; i < sz(test); i += 4) {
    //         cout << test[i] << " ";
    //     }
    //     cout << "\n";
    // }
}