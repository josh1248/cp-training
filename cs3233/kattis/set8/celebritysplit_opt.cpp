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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        vi mansions(N);
        int total = 0;
        rep(i, 0, N) {
            cin >> mansions[i];
            total += mansions[i];
        }
        int values[(1 << N)];
        unordered_map<ll, vi, custom_hash> value_to_mask;
        memset(values, -1, sizeof(values));
        function<int(int)> populate = [&](int mask) {
            if (mask == 0) return 0;
            int& ans = values[mask];
            if (ans != -1) return ans;

            int nxt = ((mask) & (-mask));
            int pos = __builtin_ctz(nxt);
            ans = mansions[pos] + populate(mask - nxt);
            return ans;
        };
        values[0] = 0;
        rep(i, 1, (1 << N)) {
            int ans = populate(i);
            // does not make sense for someone to take more than half of the value
            if (ans <= (total / 2)) {
                if (value_to_mask.count(i) == 0) value_to_mask[i] = vi();
                // prevent entry if mansions are shared
                // (some entry with removed shared properties will be present anyway)
                // additionally, prevent entry for size > 2
                bool flag = false;
                for (int& j: value_to_mask[i]) {
                    if (i & j != 0) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    value_to_mask[ans].emplace_back(i);
                }
            }
        }
        int record = 0;
        for (auto& [k, v]: value_to_mask) {
            // cout << "Probe" << k << "\n";
            rep(i, 0, sz(v)) {
                rep(j, i + 1, sz(v)) {
                    // cout << v[i] << " " << v[j] << "\n";
                    // get rid of shared properties, tally values held
                    record = max(record, values[v[i]^v[j]]);
                }
            }
        }
        cout << values[(1 << N) - 1] - record << "\n";
    }
}