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

typedef unordered_map<long long, long long, custom_hash> safe_map;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        vector<ll> mansions(N);
        rep(i, 0, N) {
            cin >> mansions[i];
        }
        ll values[(1 << N)];
        unordered_map<ll, vi, custom_hash> value_to_mask;
        memset(values, -1, sizeof(values));
        function<ll(int)> populate = [&](int mask) {
            if (mask == 0) return 0ll;
            ll& ans = values[mask];
            if (ans != -1) return values[mask];

            int nxt = ((mask) & (-mask));
            int pos = __builtin_ctz(nxt);
            ans = mansions[pos] + populate(mask - nxt);
            if (value_to_mask.count(ans) == 0) value_to_mask[ans] = vi();
            value_to_mask[ans].emplace_back(mask);
            return ans;
        };
        values[0] = 0;
        rep(i, 1, (1 << N)) {
            populate(i);
        }
        ll record = 0;
        for (auto& [k, v]: value_to_mask) {
            rep(i, 0, sz(v)) {
                rep(j, i + 1, sz(v)) {
                    // get rid of shared properties, tally values held
                    record = max(record, values[v[i]^v[j]]);
                }
            }
        }
        cout << values[(1 << N) - 1] - record << "\n";
    }
}