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

vi primes;

vi sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    rep(i, 2, n + 1) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return primes;
}

vvi factors;

void pre_factorise(int n) {
    factors = vvi(n + 1);
    for (int p: primes) {
        for (int i = p; i <= n; i += p) {
            factors[i].push_back(p);
        }
    }
}

void solve(vi& primes) {
    int n; cin >> n;
    vi nums(n), costs(n);
    rep(i, 0, n) cin >> nums[i];
    rep(i, 0, n) cin >> costs[i];

    sort(all(nums));

    // first, check for non-coprime pairs
    unordered_set<int> prev_factors;
    bool can_op_once = false;
    rep(i, 0, n) {
        for (int f: factors[nums[i]]) {
            if (prev_factors.count(f) > 0) {
                cout << 0 << "\n";
                return;
            }
        }

        // else, check if adding 1 makes it coprime to anything to the left
        for (int alt_f: factors[nums[i] + 1]) {
            if (prev_factors.count(alt_f) > 0) {
                can_op_once = true;
            }
        }

        for (int f: factors[nums[i]]) prev_factors.insert(f);
    }

    if (can_op_once) {
        cout << 1 << "\n";
        return;
    }

    // else, check if adding 1 makes it coprime to anything to the right
    prev_factors.clear();
    for (int i = n - 1; i >= 0; i--) {
        for (int f: factors[nums[i] + 1]) {
            if (prev_factors.count(f) > 0) {
                cout << 1 << "\n";
                return;
            }
        }
        for (int f: factors[nums[i]]) prev_factors.insert(f);
    }


    // else, always doable by making 2 odd numbers even
    cout << 2 << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi primes = sieve(2e5 + 1);
    pre_factorise(2e5 + 1);
    int t; cin >> t;
    while (t--) solve(primes);
}