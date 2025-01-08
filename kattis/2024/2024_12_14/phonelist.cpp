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

struct Trie {
    bool terminal = false;
    Trie* nxts[10];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; int t, n; bool flag; Trie *base, *curr;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        curr = base = new Trie();
        flag = false;
        for (int j = 0; j < n; j++) {
            cin >> s;
            if (flag) {
                continue;
            }
            curr = base;
    
            for (char c: s) {
                if (curr->nxts[c - '0'] == NULL) {
                    curr->nxts[c - '0'] = new Trie();
                    curr = curr->nxts[c - '0'];
                } else {
                    curr = curr->nxts[c - '0'];
                    if (curr->terminal) {
                        flag = true;
                    }
                }
            }

            curr->terminal = true;
            for (int k = 0; k < 10; k++) {
                if (curr->nxts[k] != NULL) {
                    flag = true;
                }
            }
        }

        if (flag) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}