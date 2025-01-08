// https://open.kattis.com/problems/rationalsequence3
// Time: 00:21
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <numeric> // accumulate
#include <set>
#include <math.h>
using namespace std;
using vi = vector<int>;

void algo(int p) {
    int layer = 0;
    int curr = p;
    while (curr - pow(2, layer) > 0) {
        curr -= pow(2, layer);
        layer += 1;
    }

    vi turns;
    for (int i = 0; i < layer; i++) {
        if (curr % 2 == 1) {
            turns.push_back(0);
            curr = (curr + 1) / 2;
        } else {
            turns.push_back(1);
            curr = curr / 2;
        }
    }
    
    int a, b;
    a = 1; b = 1;
    for (int i = turns.size() - 1; i >= 0; i--) {
        if (turns[i] == 0) {
            b += a;
        } else {
            a += b;
        }
    }
    cout << a << "/" << b;
}

int main() {
    int n, k, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> p;
        cout << k << " ";
        algo(p);
        cout << "\n";
    }
}