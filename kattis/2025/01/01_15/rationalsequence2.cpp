#include <iostream>
#include <algorithm>
#include <cstdio>
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

    int k; scanf("%d\n", &k);
    for (int i = 0; i < k; i++) {
        int n, num, denom;
        scanf("%d %d/%d\n", &n, &num, &denom);
        printf("%d ", n);
        vector<bool> path;
        while (!(num == 1 && denom == 1)) {
            if (num < denom) {
                // left child
                path.push_back(false);
                denom -= num;
            } else {
                // right child
                path.push_back(true);
                num -= denom;
            }
        }
        reverse(path.begin(), path.end());
        int res = 1;
        for (bool b: path) {
            res = res << 1;
            res += b;
        }
        printf("%d\n", res);
    }
}