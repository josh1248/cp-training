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

void solve() {
    int N; cin >> N;
    vector<ll> nums(2 * N);
    safe_map seen;
    ll acc = 0;
    rep(i, 0, 2 * N) {
        cin >> nums[i];
        seen.insert({nums[i], 1});
        acc += nums[i];
    }
    sort(all(nums));

    if (N == 1) {
        cout << nums[1] - nums[0] << " " << nums[1] << " " << nums[0] << "\n";
        return;
    } else if (N == 2) {
        rep(i, 0, 4) {
            rep(j, i + 1, 4) {
                ll res = acc - 2 * (nums[i] + nums[j]);
                if (seen.count(res) == 0 && res > 0) {
                    vector<ll> odds;
                    rep(k, 0, 4) {
                        if (k != i && k != j) {
                            odds.emplace_back(k);
                        }
                    }
                    cout << res << " " << nums[odds[0]] << " " << nums[i] << " " << nums[odds[1]] << " " << nums[j] << "\n";
                    return;
                }
            }
        }
        return;
    }

    // greedily construct a1 to be max possible
    // wont exceed 1e18 since given values are smaller than 1e9
    ll a1 = 0;
    rep(i, 0, N) {
        a1 += nums[2 * N - i - 1];
        a1 -= nums[i];
    }
    if (seen.count(a1) == 0) {
        cout << a1;
        rep(i, 0, N) {
            cout << " " << nums[2 * N - i - 1] << " " << nums[i];
        }
        cout << "\n";
    } else {
        ll a2 = 0;
        rep(i, 0, N - 1) {
            a2 += nums[2 * N - i - 1];
            a2 -= nums[i];
        }
        a2 += nums[N - 1] + nums[N];
        cout << nums[0] << " " << a2 << " " << nums[2 * N - 1];
        rep(i, 0, N - 1) {
            cout << " " << nums[i + 1] << " " << nums[2 * N - 1 - i];
        } 
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}