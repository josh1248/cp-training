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

    int t, x, y, k;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> k;

        int stepsx = ceil(x * 1.0 / k);
        int stepsy = ceil(y * 1.0 / k);

        if (stepsx > stepsy) {
            cout << 2 * stepsx - 1 << "\n";
        } else {
            cout << 2 * stepsy << "\n";
        }
    }
}