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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, q, l, r, x; vi v; unordered_map<int, int> hs;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        cin >> n >> k >> q;
        v.clear();
        hs.clear();
        for (int j = 0; j < n; j++) {
            cin >> x;
            v.push_back(x);
        }

        int longestrun, curr, curr_run;
        for (int j = 0; j < q; j++) {
            cin >> l >> r;
            
            for (int z = l - 1; z < r; z++) {
                hs[z] = v[z];
            }

            lowestuses = 0; curr = -1; curr_uses = 0;
            for (int z = l - 1; z < r; z++) {
                if (hs.count(v[z] - 1) > 0) {
                    continue;
                }

                curr = v[z];
                while (z < r) {
                    if (hs.count(curr + 1) > 0 && ) {

                    }
                }

                if (curr + 1 == v[z]) {
                    curr_run++; longestrun = max(curr_run, longestrun); curr++;
                } else {
                    curr_run = 1; longestrun = max(curr_run, longestrun); curr = v[z];
                }
            }
            cout << k - longestrun << "\n";
        }

    }
}