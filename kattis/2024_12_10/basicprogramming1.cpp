#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <numeric> // accumulate
#include <set>
using namespace std;
using vi = vector<int>;

void a1(vector<int> a) {
    cout << 7;
}

void a2(vector<int> a) {
    string s = (a[0] > a[1]) ? "Bigger" : (a[0] == a[1]) ? "Equal" : "Smaller";
    cout << s;
}

void a3(vector<int> a) {
    vector<int> o({a[0], a[1], a[2]});
    sort(o.begin(), o.end());
    cout << o[1];
}

void a4(vector<int> a) {
    // accumulate(a.begin(), a.end(), 0, [](int a, int b){ return a + b; });
    long sum = 0;
    for (int i: a) {
        sum += i;
    }
    cout << sum;
}

void a5(vi a) {
    long sum = 0;
    for (int i: a) {
        if (i % 2 == 0) {
            sum += i;
        }
    }    
    cout << sum;
}

void a6(vi a) {
    for (int i: a) {
        cout << char(i % 26 + int('a'));
    }
}

void a7(vi a) {
    int curr = 0;
    set<int> seen;
    while (true) {
        if (curr < 0 || curr >= a.size()) {
            cout << "Out";
            return;
        } else if (curr == a.size() - 1) {
            cout << "Done";
            return;
        } else if (seen.count(curr) > 0) {
            cout << "Cyclic";
            return;
        }
        seen.insert(curr);
        curr = a[curr];
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    vi z;
    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        z.push_back(a);
    }

    switch (y) {
        case 1:
        a1(z);break;
        case 2:
        a2(z);break;
        case 3:
        a3(z);break;
        case 4:
        a4(z);break;        
        case 5:
        a5(z);break;        
        case 6:
        a6(z);break;        
        case 7:
        a7(z);break;
        default:
        break;
    }
}