#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tuple<int, int, int> t3;
typedef tree<t3 , null_type, less<t3> , rb_tree_tag ,
tree_order_statistics_node_update> ordered_multiset;


using vi = vector<int>;
using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, t, p;
    cin >> n >> m;

    ordered_multiset s;
    map<int, t3> hash;

    for (int i = 1; i < n + 1; i++) {
        t3 z({0, 0, i});
        hash[i] = z;
        s.insert(z);
    }

    for (int i = 0; i < m; i++) {
        cin >> t >> p;
        tuple<int, long, int> f = hash[t];
        tuple<int, long, int> tp({get<0>(f) + 1, get<1>(f) - p, t});
        s.erase(f);
        s.insert(tp);
        hash[t] = tp;
        // get the rank of the team right above team 1
        cout << n - s.order_of_key({get<0>(hash[1]), get<1>(hash[1]), 1000000}) + 1 << "\n";

        // cout << "Current set order:\n";
        // for (auto [a, b, c]: s) {
        //     cout << a << ", " << b << ", " << c << "\n";
        // }
    }
}