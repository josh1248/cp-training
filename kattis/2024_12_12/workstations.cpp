#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <vector>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, s;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n >> m;
    vector<pi> cmds;
    for (int i = 0; i < n; i++) {
        cin >> a >> s;
        cmds.push_back({a, s});
    }

    int acc = 0;
    sort(cmds.begin(), cmds.end());
    for (auto [x, y]: cmds) {
        while (true) {
            if (pq.size() == 0 || x < pq.top()) {
                pq.push(x + y); break;
            } else if (pq.top() + m < x) {
                pq.pop();
            } else {
                pq.pop();
                pq.push(x + y);
                acc += 1;
                break;
            }
        }
    }

    cout << acc << "\n";
}