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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a;
    vi v;
    for (int i = 0; i < a; i++) {
        cin >> b;
        v.push_back(b);
    }
    v.push_back(100000);

    sort(v.begin(), v.end());

    if (a == 1) {
        cout << v[0] << "\n";
        return 0;
    } else if (a == 2) {
        cout << v[0] << " " << v[1] << "\n";
        return 0;
    }

    cout << v[0];
    int streak = 1;
    for (int i = 1; i < a + 1; i++) {
        if (v[i] - v[i - 1] == 1) {
            streak += 1;
        } else { 
            if (streak > 2) {
                cout << "-" << v[i - 1];
            } else if (streak == 2) {
                cout << " " << v[i - 1];
            }
            streak = 1;
        }

        if (streak == 1 && i != a) {
            cout << " " << v[i];
            continue;
        }
    }
}