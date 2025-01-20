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

    int d, u; cin >> d >> u;
    vi pq;
    for (int i = 1; i <= u; i++) {
        pq.push_back(-i);
    }
    make_heap(pq.begin(), pq.end());

    vi availables(u, 0);
    for (int i = 0; i < u; i++) {
        if (availables[i] != 0) {
            pq.push_back(-availables[i]);
            push_heap(pq.begin(), pq.end());
        }

        char c; cin >> c;
        if (c == 'a') {
            cout << -pq[0] << "\n";
            pop_heap(pq.begin(), pq.end());
            pq.pop_back();
        } else {
            int r; cin >> r;
            if (i + d < u) {
                availables[i + d] = r;
            }
        }
    }
    
}