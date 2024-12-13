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

void check(vector<pair<int, int>> cmds) {
    queue<int> q;
    priority_queue<int> pq;
    vi s;

    bool pflag, pqflag, sflag;
    pflag = pqflag = sflag = true;
    for (auto [a, b]: cmds) {
        if (a == 1) {
            q.push(b);
            pq.push(b);
            s.push_back(b);
        } else {
            if (q.size() == 0) {
                cout << "impossible\n";
                return;
            }

            if (b != q.front()) {
                pflag = false;
            }

            if (b != pq.top()) {
                pqflag = false;
            }

            if (b != s.at(s.size() - 1)) {
                sflag = false;
            }

            q.pop();
            pq.pop();
            s.pop_back();
        }
    }

    if (!(pflag || pqflag || sflag)) {
        cout << "impossible\n";
    } else if (pflag && !pqflag && !sflag) {
        cout << "queue\n";
    } else if (!pflag && pqflag && !sflag) {
        cout << "priority queue\n";
    } else if (!pflag && !pqflag && sflag) {
        cout << "stack\n";
    } else {
        cout << "not sure\n";
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int a;
    while (scanf("%d", &a) != EOF) {

        vector<pair<int, int>> cmds;
        for (int i = 0; i < a; i++) {
            int x, y;
            cin >> x >> y;
            cmds.push_back({x, y});
        }
        
        check(cmds);
    }
}