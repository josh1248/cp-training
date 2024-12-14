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
using vi = vector<int>;
using pi = pair<int, int>;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t, n; long long sum, acc;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        long long c[n];
        sum = 0; acc = 0;
        for (int j = 0; j < n; j++) {
            cin >> c[j];
            sum += c[j];
        }

        for (int j = 0; j < n; j++) {
            if (c[j] * n > sum) {
                acc += 1;
            }
        }

        printf("%.3f", acc * 100.0 / n);
        cout << "%\n";
    }   
}