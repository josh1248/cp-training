#include <iostream>
#include <algorithm>
#include <cstdio>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi v(n, 0);
        int idx = 0;
        for (int i = 1; i <= n; i++) {
            int shuffles = i;
            while (shuffles > 0 || v[idx] != 0) {
                if (v[idx] == 0) {
                    shuffles--;
                }
                idx++;
                if (idx >= n) {
                    idx = 0;
                }
            }
            v[idx] = i;
        }
        for (int i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}