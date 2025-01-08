#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

template <typename T>
class teque {
public:
    T lsize, rsize;
    deque<T> l, r;

    // lsize - rsize must always be 0 or 1 (left-biased)
    teque() {
        lsize = 0;
        rsize = 0;
    }

    void balance() {
        if (lsize - rsize < 0) {
            l.push_back(r.front());
            r.pop_front();
            lsize++;
            rsize--;
        } else if (lsize - rsize > 1) {
            r.push_front(l.back());
            l.pop_back();
            lsize--; rsize++;
        }
    }

    void push_back(T el) {
        r.push_back(el);
        rsize++;
        balance();
    }

    void push_front(T el) {
        l.push_front(el);
        lsize++;
        balance();
    }

    void push_middle(T el) {
        r.push_front(el);
        rsize++;
        balance();
    }

    T get(int i) {
        if (i < lsize) {
            return l.at(i);
        } else {
            return r.at(i - lsize);
        }
    }

    void print() {
        for_each(l.begin(), l.end(), [](T a){ cout << a << " "; });
        cout << "|"; 
        for_each(r.begin(), r.end(), [](T a){ cout << a << " "; });
        cout << "\n"; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; int j, k;
    teque<int> t;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> s >> j;
        if (s == "push_back") {
            t.push_back(j);
        } else if (s == "push_middle") {
            t.push_middle(j);
        } else if (s == "push_front") {
            t.push_front(j);
        } else {
            cout << t.get(j) << "\n";
        }

        // t.print();
    }
}