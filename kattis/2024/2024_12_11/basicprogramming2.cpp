#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <vector>
using namespace std;
using vi = vector<int>;

void a1(vi v) {
    set<int> s;
    for (int i: v) {
        if (s.count(i) > 0) {
            cout << "Yes\n";
            return;
        }
        s.insert(7777 - i);
    }
    cout << "No\n";
}

void a2(vi v) {
    set<int> s;
    for (int i: v) {
        if (s.count(i) > 0) {
            cout << "Contains duplicate\n";
            return;
        } else {
            s.insert(i);
        }
    }
    cout << "Unique\n";
}

void a3(vi v) {
    map<int, int> m;
    for (int i: v) {
        if (m.count(i) > 0) {
            m[i] += 1;
        } else {
            m[i] = 1;
        }

        if (m[i] > v.size() * 1 / 2) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n"; return;
}

void a4(vi v) {
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
        cout << v[v.size() / 2 - 1] << " " << v[v.size() / 2] << "\n";
    } else {
        cout << v[v.size() / 2] << "\n";
    }
}

void a5(vi v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 100 && v[i] <= 999) {
            cout << v[i];
            if (i < v.size() - 1 && v[i + 1] >= 100 && v[i + 1] <= 999) {
                cout << " ";
            } 
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, a;
    vi z;
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        cin >> a;
        z.push_back(a);
    }

    switch (y) {
        case 1:a1(z);break;
        case 2:a2(z);break;
        case 3:a3(z);break;
        case 4:a4(z);break;
        case 5:a5(z);break;
        default:break;
    }
}