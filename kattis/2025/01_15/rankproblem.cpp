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

    int n, m; scanf("%d %d\n", &n, &m);
    vi v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int win, lost; scanf("T%d T%d\n", &win, &lost);
        auto win_idx = find(v.begin(), v.end(), win);
        auto lost_idx = find(v.begin(), v.end(), lost);
        if (win_idx > lost_idx) {
            v.erase(lost_idx);
            win_idx = find(v.begin(), v.end(), win);
            v.insert(win_idx + 1, lost);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("T%d ", v[i]);
    }
    printf("\n");
}