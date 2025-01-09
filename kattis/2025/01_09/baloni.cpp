#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
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

typedef unordered_map<int, int, custom_hash> safe_map;

// always optimal to shoot an arrow at the first balloon
// an arrow must always be shot at the first balloon anyway.
// shooting it first allows it to pop other balloons downstream
// extra popping is optimal, wont cause further arrows shot to pop less ballons down the line
// (other than the balloons already popped by the first arrow)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    safe_map arrows; // track number of arrows at each height
 
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        
        // immediately generate an arrow to pop h
        if (arrows.count(h - 1) == 0) {
            arrows[h - 1] = 0;
        }
        arrows[h - 1]++;

        // see if we can re-use some earlier arrow at height h
        if (arrows.count(h) > 0) {
            arrows[h]--;
            if (arrows[h] == 0) {
                arrows.erase(h);
            }
        }
    }

    int res = 0;
    for (auto [k, v]: arrows) {
        res += v;
    }
    cout << res << "\n";
}