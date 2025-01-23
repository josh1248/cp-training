#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    l--; r--;
    vi v;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }

    multiset<int> pqleft;
    for (int i = l; i <= r; i++) {
        pqleft.insert(v[i]);        
    }
    for (int i = 0; i < l; i++) {
        int m = *pqleft.rbegin();
        pqleft.erase(--pqleft.end());
        pqleft.insert(min(m, v[i]));
    }
    ll resleft = 0;
    for (int i: pqleft) {
        resleft += ll(i);
    }

    multiset<int> pqright;
    for (int i = l; i <= r; i++) {
        pqright.insert(v[i]);        
    }
    for (int i = r + 1; i < n; i++) {
        int m = *pqright.rbegin();
        pqright.erase(--pqright.end());
        pqright.insert(min(m, v[i]));
    }
    ll resright = 0;
    for (int i: pqright) {
        resright += ll(i);
    }
    cout << min(resleft, resright) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}