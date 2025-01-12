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
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vll want(n, 0), hold(n, 0);
        for (int j = 0; j < n; j++) {
            ll k; cin >> k;
            hold[j] = k;
        }
        for (int j = 0; j < n; j++) {
            ll k; cin >> k;
            want[j] = k;
        }

        ll smallest_excess = 2e9; ll deficit_amt = 0; int deficits = 0; bool flag = false;
        for (int j = 0; j < n; j++) {
            ll gap = hold[j] - want[j];
            if (gap >= 0) {
                flag = true;
                smallest_excess = min(gap, smallest_excess);
            } else {
                deficits++;
                deficit_amt = -gap;
            } 
        }

        if (deficits >= 2 || !flag || (smallest_excess < deficit_amt)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}