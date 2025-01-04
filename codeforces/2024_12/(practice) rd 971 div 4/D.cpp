#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, xi, yi;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<bool> zeroes(n + 1, false);
        vector<bool> ones(n + 1, false);
        int zpoints = 0; int opoints = 0;
        
        for (int j = 0; j < n; j++) {
            cin >> xi >> yi;
            if (yi == 0) {
                zeroes[xi] = true;
                zpoints++;
            } else {
                ones[xi] = true;
                opoints++;
            }
        }

        // 45-90-45 with diagonal sides, or sides are horizontal and vertical
        ll counts = 0;
        for (int i = 0; i < n + 1; i++) {
            if (zeroes[i] && ones[i]) {
                counts += opoints + zpoints - 2;
            }

            if (i > 0 && i < n && zeroes[i] && ones[i - 1] && ones[i + 1]) {
                counts++;
            }
            if (i > 0 && i < n && ones[i] && zeroes[i - 1] && zeroes[i + 1]) {
                counts++;
            }
        }
        cout << counts << "\n";
    }
}