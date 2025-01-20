#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;


const ll BASE_MOD = 998'244'353;

// Fermat's little theorem to find multiplicative inverses:
// a^(-1) mod m equals a^(m-2) mod m
ll inv_fact[17];

int binpow(int x, int n) {
    int ans = 1;
    while(n) {
        if(n & 1) ans = (long long) ans * x % BASE_MOD;
        n >>= 1;
        x = (long long) x * x % BASE_MOD;
    }
    return ans;
}

void populate_inverses() {
    ll fact = 1;
    for (int i = 1; i <= 16; i++) {
        fact *= i;
        inv_fact[i] = binpow(fact, BASE_MOD - 2);
    }
}

// k as 1st number
// next number, x - number of factors (at most 16: 2 ^ 17 > 10e5)
// coordinate - different ways to decompose k to x factors and arrange them distinctly
vector<vector<ll>> precalc(1e5 + 1, vector<ll>(17));
void populate_factors(int limit) {
    for (int k = 2; k <= limit; k++) {
        precalc[k][1] = 1;
        for (int f = 2; f <= k / 2; f++) {
            if (k % f == 0) {
                // take previous decompositions and add on them
                for (int x = 1; x <= 15; x++) {
                    precalc[k][x + 1] += precalc[k / f][x];
                }
            }
        }
    }
}

void solve() {
    int k, n; cin >> k >> n;
    vector<ll> base(min(n, 17));
    
    // ((n + 1) choose (number of factors + 1)) * ways to rearrange factors
    // pick f + 1 marbles out of n + 1, right marble is the right array bound and
    // the f marbles are the factors
    ll f = n + 1;
    for (int i = 1; i < base.size(); i++) {
        f *= (n + 1 - i);
        f %= BASE_MOD;
        base[i] = (f * inv_fact[i + 1]) % BASE_MOD;
    }

    // x = 1
    cout << n << " ";
    for (int x = 2; x <= k; x++) {
        ll res = 0;
        for (int f = 1; f <= 16; f++) {
            res += precalc[x][f] * base[f];
            res %= BASE_MOD;
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    populate_factors(1e5);
    populate_inverses();

    int t; cin >> t;
    while (t--) {
        solve();
    }
}