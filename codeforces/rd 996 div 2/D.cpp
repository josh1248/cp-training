#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef long long ll;
typedef priority_queue<int, vi, greater<int>> minpq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int crow_pos = 0;
        int s_idx = 0;
        int time_passed = 0;

        vi scarecrows;
        int n, k, l; cin >> n >> k >> l;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            scarecrows.push_back(x);
        }
        scarecrows.push_back(2e9);

        // let the first scarecrow travel to position 0
        time_passed = scarecrows[0];
        crow_pos = k;
        if (crow_pos >= l) {
            cout << time_passed * 2 << "\n";
            continue;
        }

        while (true) {
            int optimal_pos;
            if (scarecrows[s_])
            if (scarecrows[s)
        }
    }
}