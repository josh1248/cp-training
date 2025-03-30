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

// ways to break down a number into distinct numbers 
vector<vector<vi>> partitions(63);

void populate_partition(int total, int m, vi& curr, int s) {
    if (s == total) {
        partitions[total].push_back(curr);
    } else if (s > total) {
        return;
    }

    rep(i, m, min(total - s + 1, 16)) {
        curr.push_back(i);
        populate_partition(total, i + 1, curr, s + i);
        curr.pop_back();
    }
}

void populate_all_partitions() {
    rep(i, 0, 63) {
        vi v;
        populate_partition(i, 1, v, 0);
    }
}

// input (x, y): shift left num by x bits, right num by y bits
// output: min cost possible
vector<vector<ll>> mincosts(63, vector<ll>(63));

void populate_at(int i, int j) {
    mincosts[i][j] = 4e18;
    for (vi& iset: partitions[i]) {
        for (vi& jset: partitions[j]) {
            vi shared;
            set_intersection(all(iset), all(jset), back_inserter(shared));
            if (sz(shared) > 0) {
                continue;
            } else {
                ll cost = 0;
                for (int& i: iset) {
                    cost += (1 << i);
                }
                for (int& j: jset) {
                    cost += (1 << j);
                }
                mincosts[i][j] = min(mincosts[i][j], cost);
            }
        }
    }
}

void populate_mincosts() {
    // for number of bits to shift for each num
    rep(i, 0, 63) {
        rep(j, i, 63) {
            populate_at(i, j);
            mincosts[j][i] = mincosts[i][j];
        }
    }

    cout << "ll mincosts[63][63] = {";
    rep(i, 0, 63) {
        cout << "{";
        cout << mincosts[i][0];
        rep(j, 1, 63) {
            cout << "," << mincosts[i][j];
        }
        cout << "},\n";
    }
    cout << "};";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    populate_all_partitions();
    populate_mincosts();
    // int t; cin >> t; while (t--) solve();
}