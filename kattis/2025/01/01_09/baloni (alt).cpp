#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
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

// always optimal to shoot an arrow at the first balloon
// an arrow must always be shot at the first balloon anyway.
// shooting it first allows it to pop other balloons downstream
// extra popping is optimal, wont cause further arrows shot to pop less ballons down the line
// (other than the balloons already popped by the first arrow)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> left;
    vector<set<int>> heights(1'000'001, set<int>());
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        left[i] = h;
        heights[h].insert(i);
    }

    int res = 0;
    while (left.size() > 0) {
        // cout << "Arrow " << res + 1 << ": ";
        res++;

        int idx, h;
        auto [x, y] = *left.begin();
        idx = x; h = y;
        // cout << "(" << h << ", " << idx << ") ";

        left.erase(idx);
        heights[h].erase(idx);
        
        while (true) {
            h--;
            auto nxt = heights[h].upper_bound(idx);
            if (nxt == heights[h].end()) {
                // cout << "\n";
                break;
            } else {
                idx = *nxt;
                left.erase(idx);
                heights[h].erase(idx);
                // cout << "(" << h << ", " << idx << ") ";
            }
        }
    }
    cout << res << "\n";
}