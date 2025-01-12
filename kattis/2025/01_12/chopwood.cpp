#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l; cin >> l;

    vi queries(l, 0);
    vi last(l + 2, -1);
    for (int i = 0; i < l; i++) {
        int v; cin >> v;
        queries[i] = v;
        last[v] = i;
    }

    if (queries[l - 1] != (l + 1)) {
        cout << "Error\n";
        return 0;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= l + 1; i++) {
        if (last[i] == -1) {
            pq.push(-i);
        }
    }

    for (int i = 0; i < l; i++) {
        int u = pq.top();
        pq.pop();
        cout << -u << "\n";
        if (last[queries[i]] == i) {
            pq.push(-queries[i]);
        }
    }
    
}