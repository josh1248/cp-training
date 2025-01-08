#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

/*
Greedy algo: in zigzag, clearly always optimal to take most extreme (i.e. last) element in a monotone sequence
Additionally, if zigzag is offered, always optimal to take it rather than wait
e.g.: x + 5, x, y, ..., z, w
zigzag means x < y.
then take y to increase seq by 1.
if z > y, then x, y will be updated to x, z. repeat until z < y is seen.
if z < y, then x, y, z (seq1) is an up-down sequence, while x, z (seq2) is a up sequence
     if z > w, seq1 becomes x, y, w, seq2 becomes x, z, w - equal.
     if z < w, seq1 becomes x, y, z, w, seq2 becomes z, w, which is shorter than seq1 without any upside
in both cases, greedily taking every incoming element as a replacement or extension is always equal or better.

Optimization: can apply greedy for first 2 numbers as well - but annoying to handle similar first elements - 0, 0, 0.
*/

int solve1(vi& v, bool init_dir) {
    int res = 1;
    bool dir = init_dir;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) {
            if (!dir) {
                dir = !dir;
                res++;
            }
        } else if (v[i] < v[i - 1]) {
            if (dir) {
                dir = !dir;
                res++;
            }
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vi v(n , 0);
    int m;
    for (int i = 0; i < n; i++) {
        cin >> m;
        v[i] = m;
    }

    cout << max(solve1(v, true), solve1(v, false)) << "\n";
}