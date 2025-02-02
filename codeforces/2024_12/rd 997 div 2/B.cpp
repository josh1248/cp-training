#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
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
        int v; cin >> v;
        vi perm(v + 1, -1);

        for (int i = 1; i <= v; i++) {
            string s; cin >> s;
            int edges_seen = 0;
            for (int j = i + 1; j <= v; j++) {
                if (s[j - 1] == '1') {
                    edges_seen++;
                }
            }

            // position in unfilled array
            for (int k = v; k >= 1; k--) {
                if (perm[k] == -1) {
                    if (edges_seen == 0) {
                        perm[k] = i;
                        break;
                    } else {
                        edges_seen--;
                    }
                }
            }
        }

        for (int i = 1; i <= v; i++) {
            cout << perm[i];
            if (i != v) {
                cout << " ";
            }
        }
        cout << "\n";
    } 
}