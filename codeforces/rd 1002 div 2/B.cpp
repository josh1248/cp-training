#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int small = 1, large = n - k + 1;
        int cost = 1;
        if (large == small) {
            int cost = 1;
            while (cost <= k / 2) {
                if (v[large] != cost) {
                    break;
                }
                large += 2;
                small = large;
                cost++;
            }
            cout << cost << "\n";
        } else {
            bool flag = true;
            for (int i = small; i <= large; i++) {
                if (v[i] != 1) {
                    cout << 1 << "\n";
                    flag = false;
                    break;
                }
            }

            if (flag) cout << 2 << "\n";
        }
    }
}