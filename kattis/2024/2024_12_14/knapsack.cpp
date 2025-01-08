#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
typedef tuple<int, int, int> t3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, w, v;
    while (cin >> c >> n) {
        
        vector<t3> items(n);
        int cache[c + 1][n + 1];
        bool chosen[c + 1][n + 1];
        
        for (int i = 0; i < n; i++) {
            cin >> v >> w;
            items[i] = {v, -w, i};
        } 
        
        sort(items.begin(), items.end());

        for (int i = 0; i < c + 1; i++) {
            cache[i][0] = 0;
            chosen[i][0] = false;
        }

        for (int i = 0; i < n + 1; i++) {
            cache[0][i] = 0;
            chosen[0][i] = false;
        }

        for (int i = 1; i < c + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                // use current item
                t3 val = items[j - 1];
                int use;
                if (-get<1>(val) > i) {
                    use = 0;
                } else {
                    use = get<0>(val) + cache[i + get<1>(val)][j - 1];
                }

                // dont use
                int alt = cache[i][j - 1];

                if (use > alt) {
                    cache[i][j] = use;
                    chosen[i][j] = true;
                } else {
                    cache[i][j] = alt;
                    chosen[i][j] = false;
                }
            }
        }

        int i = c; int j = n; vi indices;
        while (i > 0 && j > 0) {
            if (chosen[i][j]) {
                indices.push_back(get<2>(items[j - 1]));
                i += get<1>(items[j - 1]);
            }
            j -= 1;
        }
        cout << indices.size() << "\n";
        for (int idx: indices) {
            cout << idx << " ";
        }
    }
} 