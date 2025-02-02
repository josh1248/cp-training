#include <iostream>
#include <algorithm> // sort
// #include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k; vi v; unordered_map<int, int> s;
        cin >> n >> k;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (s.count(x) > 0) {
                s[x]++;
            } else {
                s[x] = 1;
            }
        }

        for (auto [_, c]: s) {
            v.push_back(c);
        }
        v.push_back(1e9); // right bounds
        sort(v.begin(), v.end());

        if (n <= k) {
            cout << 1 << "\n";
            continue;
        }

        for (int j = 0; j < v.size(); j++) {
            k -= v[j];
            if (k < 0) {
                cout << v.size() - j - 1 << "\n";
                break;
            }
        }
    }
}