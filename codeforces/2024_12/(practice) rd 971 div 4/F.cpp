#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;

// remaining 4 cycles 3 (query 19)
// [0 1 2 3 4 1 2 3 4 0 2 3 4 0 1 3 4 0 1 2] -> 30 + 8
// [3 4 0 1 2]
// rights = (4 + 3 - 1) % 5 = 1; [1 0 4 3]
// 3 4 0 1
// S1 + S4 - S2
// wraparound = 1 + 5 - 4 = 2;

__int128_t query(vector<__int128_t>& v, int l, int r) {
    if (r <= 0) {
        return 0;
    }

    ll cycles = r / v.size();
    int remaining = r % v.size();
    __int128_t acc = 0;
    if (l > 1) {
        acc -= query(v, 1, l - 1);
    }
    acc += cycles * v[v.size() - 1];

    int rights = (remaining + cycles - 1) % v.size();
    if (rights - remaining >= 0) {
        return acc + v[rights] - v[rights - remaining]; 
    } else if (rights - remaining == 0) {
        return acc + v[rights];
    } else {
        int wraparound = rights + v.size() - remaining;
        return acc + v[rights] + v[v.size() - 1] - v[wraparound]; 
    }
    return acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q, l, r; vector<__int128_t> prefixes; ll x;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        cin >> n >> q;
        prefixes.clear();
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (j == 0) {
                prefixes.push_back(x);
            } else {
                prefixes.push_back(__int128_t(x) + prefixes[j - 1]);
            }
        }

        for (int j = 0; j < q; j++) {
            cin >> l >> r;
            ll a = query(prefixes, l, r);
            cout << a << "\n";
        }
    }
}