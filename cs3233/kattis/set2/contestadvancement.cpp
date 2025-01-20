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

    int n, k, c; cin >> n >> k >> c;
    safe_map counts;
    vector<pi> data;
    vector<bool> qualified(n, false);
    for (int i = 0; i < n; i++) {
        int t, s; cin >> t >> s;
        data.emplace_back(t, s);
    }

    int remaining = k;
    for (int i = 0; i < n && remaining > 0; i++) {
        if (qualified[i]) {
            continue;
        }

        auto [t, s] = data[i];
        if (counts.count(s) == 0) {
            counts[s] = 0;
        }
        if (counts[s] >= c) {
            continue;
        } else {
            qualified[i] = true;
            counts[s]++;
            remaining--;
        }
    }

    for (int i = 0; i < n && remaining > 0; i++) {
        if (qualified[i]) {
            continue;
        } else {
            qualified[i] = true;
            remaining--;
        }
    } 

    for (int i = 0; i < n; i++) {
        if (qualified[i]) {
            cout << data[i].first << "\n";
        }
    }
}