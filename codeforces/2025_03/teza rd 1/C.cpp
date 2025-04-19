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
int N;
ll f(ll a, ll b) {
    return a * (N + 1) + b;
}

void solve() {
    cin >> N;
    vi a(N), b(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];
    int samePairPos = -1;
    safe_map pairMap;

    rep(i, 0, N) {
        // pairs must be matching - (x, y) or (y, x)
        // x == y can only happen once for odd length arrays - be in the middle
        // if unmatched, impossible
        if (a[i] == b[i]) {
            if (N % 2 == 0 || samePairPos != -1) {
                cout << -1 << "\n";
                return;
            } else {
                samePairPos = i;
            }
        } else {
            pairMap[f(a[i], b[i])] = i;
        }
    }

    vector<pi> ops;
    if (N % 2 == 1) {
        if (samePairPos == -1) {
            cout << -1 << "\n";
            return;
        } else {
            if (N / 2 != samePairPos) {
                ops.emplace_back(N / 2, samePairPos);
                pairMap[f(a[N / 2], b[N / 2])] = samePairPos;
                pairMap[f(a[samePairPos], b[samePairPos])] = N / 2;
                swap(a[N / 2], a[samePairPos]);
                swap(b[N / 2], b[samePairPos]);
            }
        }
    }

    rep(i, 0, N / 2) {
        if (pairMap.count(f(b[i], a[i])) == 0) {
            cout << -1 << "\n";
            return;
        }
        int swappedPlace = pairMap[f(b[i], a[i])];
        if (swappedPlace == N - 1 - i) continue;
        ops.emplace_back(swappedPlace, N - 1 - i);

        pairMap[f(b[i], a[i])] = N - 1 - i;
        pairMap[f(a[N - 1 - i], b[N - 1 - i])] = swappedPlace;
        swap(a[swappedPlace], a[N - 1 - i]);
        swap(b[swappedPlace], b[N - 1 - i]);
    }

    cout << sz(ops) << "\n";
    for (auto& [a, b]: ops) {
        cout << min(a, b) + 1 << " " << max(a, b) + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}