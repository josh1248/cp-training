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

    long x;
    vi v;
    while (true) {
        cin >> x;
        if (x == 0) {
            return 0;
        }

        int l = -1;

        int f = 2; int streak = 0; long curr = abs(x);
        while (f <= 65536) {
            if (curr == 1) {
                if (streak > 0) {
                    if (l == -1) {
                        l = streak;
                    } else {
                        l = gcd(l, streak);
                    }
                }
                break;
            }

            if (f != 2 && f % 2 == 0) {
                f++;
                continue;
            }

            if (curr % f == 0) {
                streak += 1;
                curr /= f;
            } else {
                if (streak > 0) {
                    if (l == -1) {
                        l = streak;
                    } else {
                        l = gcd(l, streak);
                    }
                }
                streak = 0;
                f++;
            }
        }

        if (f > 65536) {
            cout << 1 << "\n";
            continue;
        }
            
        if (x < 0) {
            while (l % 2 == 0) {
                l /= 2;
            }
        }
        cout << l << "\n";
        
    }

}