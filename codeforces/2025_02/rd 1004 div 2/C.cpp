#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

// Credit: https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unordered_map<long long, int, custom_hash> safe_map;

ll pows[9] = {
    9,
    99,
    999,
    9999,
    99999,
    999999,
    9999999,
    99999999,
    999999999
};

map<ll, ll> cachebig;

bool check(string s) {
    for (char c: s) {
        if (c == '7') return true;
    }
    return false;
}

ll solve(ll x) {
    if (cachebig.count(x) > 0) {
        return cachebig[x];
    }
    cachebig[x] = 7; // can always add "999999..." * 7 to guarantee a 7

    queue<pair<ll, int>> q;
    q.emplace(x, 0);
    while (sz(q)) {
        auto [v, turns] = q.front(); q.pop();
        // cout << v << " " << turns << "\n";
        if (turns >= 7) {
            break;
        }

        if (check(to_string(v))) {
            cachebig[x] = min(cachebig[x], ll(turns));
            break;
        }

        for (int i = 0; i < sz(to_string(x)); i++) {
            q.emplace(v + pows[i], turns + 1);
        }
    }
    return cachebig[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) {
        ll x; cin >> x;
        cout << solve(x) << "\n";
    }
}