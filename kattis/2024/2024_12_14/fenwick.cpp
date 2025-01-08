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

int LSOne(ll s) { return s & -s; }

class FT {
private:
    vector<long long> v;
public:
    FT(int m) {
        v = vector<long long>(m + 1, 0);
    }
    
    ll query(int q) {
        ll acc = 0; int curr = q;
        while (curr > 0) {
            acc += v[curr];
            curr -= LSOne(curr);
        }
        return acc;
    }

    void update(int k, int freq) {
        ll curr = k;
        while (curr <= v.size() - 1) {
            v[curr] += freq;
            curr += LSOne(curr);
        }
        return;
    }
    
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q, k, f; char op;
    cin >> n >> q;
    FT ft(n);
    for (int i = 0; i < q; i++) {
        cin >> op >> k;
        if (op == '?') {
            cout << ft.query(k) << "\n";
        } else {
            cin >> f;
            ft.update(k + 1, f); 
        }
    }
}