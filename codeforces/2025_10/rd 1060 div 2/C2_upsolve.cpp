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

vvi factors;

// combine prime sieve and factorisation
void pre_factorise(int n) {
    factors = vvi(n + 1);
    rep(i, 2, n + 1) {
        if (factors[i].size() > 0) continue;
        for (int j = i; j <= n; j += i) {
            factors[j].push_back(i);
        }
    }
}

void solve() {
    int n; cin >> n;
    vi nums(n), costs(n);
    rep(i, 0, n) cin >> nums[i];
    rep(i, 0, n) cin >> costs[i];

    int lo_1 = INT_MAX, lo_2 = INT_MAX, lo_1_idx = -1;
    rep(i, 0, n) {
        if (costs[i] <= lo_1) {
            lo_2 = lo_1;
            lo_1 = costs[i];
            lo_1_idx = i;
        } else if (costs[i] <= lo_2) {
            lo_2 = costs[i];
        }
    }

    // always possible to make two lowest cost numbers even
    int best_ans = lo_1 + lo_2;


    // first, check for non-coprime pairs
    unordered_set<int> prev_factors;
    rep(i, 0, n) {
        for (int f: factors[nums[i]]) {
            if (prev_factors.count(f) > 0) {
                cout << 0 << "\n";
                return;
            }
        }

        // else, check if adding 1 makes it non-coprime to anything to the left
        for (int alt_f: factors[nums[i] + 1]) {
            if (prev_factors.count(alt_f) > 0) {
                best_ans = min(best_ans, costs[i]);
            }
        }

        for (int f: factors[nums[i]]) prev_factors.insert(f);
    }

    // check if adding 1 makes it non-coprime to anything to the right
    prev_factors.clear();
    for (int i = n - 1; i >= 0; i--) {
        for (int f: factors[nums[i] + 1]) {
            if (prev_factors.count(f) > 0) {
                best_ans = min(best_ans, costs[i]);
            }
        }
        for (int f: factors[nums[i]]) prev_factors.insert(f);
    }

    // else, only way to do better is doing more than 1 op on lowest cost number,
    // and 0 ops on others.
    // all other cases will be at least as large as lo_1 + lo_2.
    prev_factors.clear();
    rep(i, 0, n) {
        if (i != lo_1_idx) {
            for (int p: factors[nums[i]]) {
                prev_factors.insert(p);
            }
        }
    }
    int lowest_ops = INT_MAX;
    for (int p: prev_factors) {
        // special case for remainder == 0 cannot happen, covered in non-coprime check
        int ops_to_do = p - nums[lo_1_idx] % p;
        lowest_ops = min(lowest_ops, ops_to_do);
    }
    int ops_lo = int(min(ll(2e9), ll(lowest_ops) * lo_1));
    best_ans = min(best_ans, ops_lo);
    cout << best_ans << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pre_factorise(2e5 + 1);
    int t; cin >> t;
    while (t--) solve();
}