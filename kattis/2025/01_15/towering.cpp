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

    vi v(6); int t1, t2;
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    cin >> t1 >> t2;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (v[i] + v[j] + v[k] == t1) {
                    vi res1({v[i], v[j], v[k]});
                    sort(res1.rbegin(), res1.rend());
                    for (int i: res1) {
                        cout << i << " ";
                    }

                    vi res2;
                    for (int l = 0; l < 6; l++) {
                        if (l != i && l != j && l != k) {
                            res2.push_back(v[l]);
                        }
                    }
                    sort(res2.rbegin(), res2.rend());
                    for (int i: res2) {
                        cout << i << " ";
                    }
                    cout << "\n";
                    return 0;
                }
            }
        }
    }
}