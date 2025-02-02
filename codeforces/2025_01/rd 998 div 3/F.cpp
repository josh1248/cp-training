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
ll factorials[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000};


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

typedef unordered_map<ll, ll, custom_hash> safe_map;

// k as 1st number
// next number, x - number of factors (at most 16: 2 ^ 17 > 10e5)
// coordinate - vector of different ways to decompose k to x factors
vector<vector<set<set<int>>>> precalc(10e5 + 1, vector<set<set<int>>>(16));
vector<vector<ll>> modifiers(10e5 + 1, vector<ll>(16, 0));
void populate_factors(int limit) {
    for (int k = 2; k <= limit; k++) {
        precalc[k][0].insert({k});
        for (int f = 2; f * f <= k; f++) {
            if (k % f == 0) {
                // take previous decompositions of f and add on them
                for (int n = 0; n < 15; n++) {
                    for (auto s: precalc[k / f][n]) {
                        s.insert(f);
                        precalc[k][n + 1].insert(s);
                    }
                }
            }
        }

        for (int n = 0; n < 16; n++) {
            for (auto s: precalc[k][n]) {
                safe_map counts;
                ll res = factorials[s.size()];
                for (int var: s) {
                    if (counts.count(var) == 0) {
                        counts[var] = 0;
                    }
                    counts[var]++;
                    res /= factorials[counts[var]];
                }
                modifiers[k][n] += res;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    populate_factors(100000);
}