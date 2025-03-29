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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K, B; cin >> N >> K >> B;
    vector<ll> vals(N);
    rep(i, 0, N) {
        cin >> vals[i];
        vals[i] -= K;
    }
    safe_map prefixsums;
    ll s = 0;
    prefixsums[0] = -1;
    pair<ll, ll> bestpair = {1e8, 1e8};
    rep(i, 0, N) {
        s += vals[i];
        if (prefixsums.count(s - B) > 0) {
            bestpair = min(bestpair, {prefixsums[s - B] + 1, i});
        }
        if (prefixsums.count(s) == 0) {
            prefixsums[s] = i;
        }
    }
    if (bestpair == pair<ll, ll>(1e8, 1e8)) {
        cout << -1 << "\n";
    } else {
        cout << bestpair.first << " " << bestpair.second << "\n";
    }
    return 0;
}