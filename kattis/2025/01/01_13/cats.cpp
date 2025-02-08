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
        int m, c; cin >> m >> c;
        vi cats(c, 0);
        vvi pairs(c, vi(c, 0));
        for (int i = 0; i < c / 2 * (c + 1); i++) {
            int x, y, d; cin >> x >> y >> d;
            if (x > y) {
                swap(x, y);
            }
            pairs[x][y] = d;
        }

        // need to find minimum spanning tree
        // each edge is the amount of milk spilled
        // should not traverse the edge more than once holding milk (can backtrack)
    }
}