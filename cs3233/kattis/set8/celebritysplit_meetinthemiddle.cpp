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
        
        // using "meet in the middle" here makes life easier
        // we can do 2Sum-like target of 0
        int L = N / 2, R = N - L;
        int mansionsleft[L], mansionsright[R];
        int total = 0;
        rep(i, 0, L) {
            cin >> mansionsleft[i];
            total += mansionsleft[i];
        }
        rep(i, 0, R) {
            cin >> mansionsright[i];
            total += mansionsright[i];
        }
        if (N == 1) {
            cout << mansionsright[0] << "\n";
            continue;
        }
        int valuesleft[1 << L], valuesright[1 << R];
        memset(valuesleft, -1, sizeof(valuesleft));
        memset(valuesright, -1, sizeof(valuesright));
        function<int(int, int[], int[])> populate = [&](int mask, int vals[], int mansions[]) {
            if (mask == 0) return 0;
            int& ans = vals[mask];
            if (ans != -1) return ans;

            int nxt = ((mask) & (-mask));
            int pos = __builtin_ctz(nxt);
            ans = mansions[pos] + populate(mask - nxt, vals, mansions);
            return ans;
        };
        valuesleft[0] = valuesright[0] = 0;
        rep(i, 1, (1 << L)) {
            populate(i, valuesleft, mansionsleft);
        }
        rep(i, 1, (1 << R)) {
            populate(i, valuesright, mansionsright);
        }
             
        // generate 2 numbers in left partition
        // get all possible differences into a set
        // for each difference, greedily take the one with most mansion value taken
        unordered_map<int, int, custom_hash> diff_to_mask_left, diff_to_mask_right;
        rep(i, 0, (1 << L)) {
            rep(j, 0, (1 << L)) {
                if ((i & j) != 0) continue;
                int diff = valuesleft[i] - valuesleft[j];
                if (diff_to_mask_left.count(diff) == 0) {
                    diff_to_mask_left[diff] = 0;
                }
                diff_to_mask_left[diff] = max(valuesleft[i|j], diff_to_mask_left[diff]);
            }
        }

        // repeat for the right partition
        rep(i, 0, (1 << R)) {
            rep(j, 0, (1 << R)) {
                if ((i & j) != 0) continue;
                int diff = valuesright[i] - valuesright[j];
                if (diff_to_mask_right.count(diff) == 0) {
                    diff_to_mask_right[diff] = 0;
                }
                diff_to_mask_right[diff] = max(valuesright[i|j], diff_to_mask_right[diff]);
            }
        }
        // now, solve 2Sum style, and obtain highest retained property value
        int record = 0;
        for (auto& [diff, val1]: diff_to_mask_left) {
            if (diff_to_mask_right.count(-diff) == 0) continue;
            record = max(record, val1 + diff_to_mask_right[-diff]);
        }
        cout << total - record << "\n";
    }
}