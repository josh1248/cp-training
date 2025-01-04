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

    int t, n; string s; vi v;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        v.clear();
        for (int j = 0; j < n; j++) {
            cin >> s;
            v.push_back(s.find('#') + 1);
        }

        reverse(v.begin(), v.end());

        for (int x: v) {
            cout << x << " ";
        }
        cout << "\n";
    }  
}