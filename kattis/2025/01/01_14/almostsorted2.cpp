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
ll inf = 10e17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    // should flip monotone in array at most twice, starting with asccending
    int flipstate = 0; 
    // need to check that when flipping reversed subarray, bounds are in order
    int peak1, peak2;

    vi v; v.push_back(-1e9); // honorary first member

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k > v[v.size() - 1]) {
            if (flipstate == 1) {
                peak2 = v.size() - 1;
                flipstate++;
            }
            v.push_back(k);
        } else if (k < v[v.size() - 1]) {
            if (flipstate == 0) {
                peak1 = v.size() - 1;
                flipstate++;
            } else if (flipstate == 2) {
                cout << "No\n";
                return 0;
            }
            v.push_back(k);
        } else {
            // repeats can be ignored
            // 2 cases: part of monotone, or as a peak
            // if monotone, then it will not affect almost sorted checking
            // if part of a peak, e.g. 1 2 30 30 30 20 12 5 4 20 ..., then
            // it is always optimal to pick all '30' - otherwise, chosen index would surely be
            // out of order, since a_j < a_i <= 30.
            // similar logic for the down-up peak.
            continue;
        }
        
    }

    // cout << flipstate << " " << peak1 << " " << peak2 << "\n";
    if (flipstate == 0) {
        cout << "Yes\n";
    } else if (flipstate == 1) {
        // always optimal to include peak in the decreasing subarray
        cout << (v[peak1 - 1] <= v[v.size() - 1] ? "Yes" : "No") << "\n";
    } else {
        // with similar logic, both peaks must be in the decreasing subarray
        cout << (v[peak1 - 1] <= v[peak2] && v[peak1] <= v[peak2 + 1] ? "Yes" : "No") << "\n";
    }
}