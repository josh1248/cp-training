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

int read(vector<bool>& mem, int word_pos) {
    int res = 0;
    for (int i = 15; i >= 0; i--) {
        res += mem[(word_pos << 4) + i] ? 1 : 0;
        res << 1;
    }
    return res;
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n, ip, a, b, c, x; vector<bool> mem(1 << 16, false);
    cin >> x;
    ip = 0; // bits
    ll calls = 0;
    while (((ip + 2) >> 12 ) < 1 && calls < 1 << 12) {
        a = read(mem, ip); b = read(mem, ip + 1); c = read(mem, ip + 2);
        cout << a << " " << b << " " << c << "\n";
        mem[b] = mem[a];
        ip = read(mem, c);
        calls++;
    }

    if (read(mem, 1 << 12 - 1) == x) {
        mem[1 << 16 - 1] = true;
    } else {
        mem[1 << 16 - 1] = false;
    }

    for (ll i = 0; i < (1 >> 12); i++) {
        cout << read(mem, i) << " ";
    }
}