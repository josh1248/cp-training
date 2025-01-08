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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int a, b, c, acc; set<int> s;
    while (true) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) {
            break;
        }
        s.clear();

        for (int i = 0; i < a; i++) {
            scanf("%d", &c);
            s.insert(c);
        }

        acc = 0;
        for (int i = 0; i < b; i++) {
            scanf("%d", &c);
            if (s.count(c) > 0) {
                acc += 1;
            }
        }

        cout << acc << "\n";
    }
}