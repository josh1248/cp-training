#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

// range sum query DSA - sum of values between two selected integers.

// static DSA - prefix sums + inclusion-exclusion
// O(n) pre-processing, O(1) point queries, O(1) interval queries
class SparseTable {
private:
    vector<ll> prefixes;
public:
    SparseTable(vi& v) {
        if (v.size() == 0) {
            return;
        }
        prefixes.push_back(v[0]);
        for (int i = 1; i < v.size(); i++) {
            prefixes.push_back(prefixes[i - 1] + v[i]);
        }
    }

    ll rsq(int i) {
        if (i < 0 || i >= prefixes.size()) {
            return 0;
        }
        return prefixes[i];
    }

    ll rsq(int i, int j) {
        // inclusion-exclusion principle
        return rsq(j) - rsq(i - 1);
    }
};

// Dynamic DSA - Fenwick Tree / Binary Indexed Tree (BIT)
// tree is arranged with subnodes based on powers of 2.

// ft[i] is in charge of maintaining frequencies in interval [i - LSOne(i) + 1..i].
// Example: 6 = (110)_2 maintains frequencies in interval [5..6]
// ft[0] is left blank because 0 is the terminating condition.

# define LSOne(S) ((S) & (-S))
// Form 1: Point update, Range query. O(log m) updates and O(log n) query, where m = capacity and n = query interval
class PURQ {
private:
    vector<ll> freqs;
public:
    PURQ(int m) {
        freqs.assign(m + 1, 0);
    }

    void update(int i, int val) {
        // 
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}