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
typedef long double ld;
ll inf = 10e17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld d = 0; int n; ll steps = 0;
    cin >> d >> n;
    // first step does not fully cover 1 meter
    // we need to check the permissible "offset" to the left for this first step
    ld min_offset = 0, max_offset = 1;
    // cout << min_offset << " " << max_offset << "\n";

    for (int i = 1; i <= n; i++) {
        ll k; cin >> k;
        steps += k;

        // steps - offset <= i * d <= steps + 1 - offset
        min_offset = max(min_offset, steps - i * d); max_offset = min(max_offset, steps + 1 - i * d);
        // cout << min_offset << " " << max_offset << "\n";
    }
    
    cout << ((min_offset >= 0 && max_offset <= 1 && min_offset <= max_offset) ? "possible" : "impossible") << "\n";
}