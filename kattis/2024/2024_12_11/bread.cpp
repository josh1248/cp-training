#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <queue>
#include <vector>
using namespace std;
using vi = vector<int>;

int accum = 0;

pair<vi, vi> split(vi x) {
    vi a, b;
    a.insert(a.end(), x.begin(), x.begin() + x.size() / 2);
    b.insert(b.end(), x.begin() + x.size() / 2, x.end());
    return {a, b};
}

vi merge(vi x, vi y) {
    vi c;
    auto a = x.begin();
    auto b = y.begin();
    while (true) {
        if (a == x.end()) {
            c.insert(c.end(), b, y.end());
            return c;
        } else if (b == y.end()) {
            c.insert(c.end(), a, x.end());
            return c;
        } else {
            if (*a <= *b) {
                c.push_back(*a);
                a++;
            } else {
                c.push_back(*b);
                b++;
                accum += x.end() - a;
            }
        }
    }
}

vi msort(vi x) {
    if (x.size() <= 1) {
        return x;
    }

    auto [a, b] = split(x);
    return merge(msort(a), msort(b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    vi y, z;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        y.push_back(a);
    }

    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        z.push_back(a);
    }

    msort(y);
    msort(z);
    if (accum % 2 == 0) {
        cout << "Possible" << "\n";
    } else {
        cout << "Impossible" << "\n";
    }

}