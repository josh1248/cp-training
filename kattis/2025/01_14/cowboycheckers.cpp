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
typedef long double ld;
ll inf = 10e17;

// each row of 3, except the middle row which counts as 2 disconnected rows (rows 3 (left), 4 (right))
// 1 - white taken, 0 - empty, -1 - black taken
// double mills check:
// 1 row (or column) has exactly 2 white and 1 blank
// based on blank, check adjacent row(s) which must be full 
// AND white piece can move to blank to fulfill double mill
vvi rows(8, vi(3, 0)), cols(8, vi(3, 0));

bool is_full(vvi& v, int i) {
    return (v[i][0] == 1) && (v[i][1] == 1) && (v[i][2] == 1);
}

// returns position of blank, -1 if not a 2-white 1-blank row
int get_blank(vvi& v, int i) {
    int whites = 0, pos = -1;
    for (int j = 0; j < 3; j++) {
        if (v[i][j] == 1) {
            whites++;
        } else if (v[i][j] == -1) {
            return -1;
        } else {
            pos = j;
        }
    }

    return ((whites == 2) ? pos : -1);
}

// mapping of row and missing position to row(s) to check
const vector<vvi> rows_to_check = {
    {{3}, {1}, {4}},
    {{3}, {0, 2}, {4}},
    {{3}, {1}, {4}},
    {{0, 7}, {1, 6}, {2, 5}},
    {{2, 5}, {1, 6}, {0, 7}}, // top-down and left-right reflection
    {{3}, {6}, {4}},
    {{3}, {5, 7}, {4}},
    {{3}, {6}, {4}},
};

// check if r is involed in a double mill as a 1-blank row
bool has_double_mill(vvi& v, int r) {
    int p = get_blank(v, r);
    if (p == -1) {
        return false;
    }

    for (int x: rows_to_check[r][p]) {
        if (is_full(v, x)) {
            return true;
        }
    }

    return false;
}

// returns the grid coordinate to obtain row[r][pos] (symmetrical for columns)
pi coords(int r, int pos) {
    if (r < 3) {
        return {r, r + (3 - r) * pos};
    } else if (r == 3) {
        return {r, pos};
    } else {
        auto [r_ref, c_ref] = coords(7 - r, 2 - pos);
        return {6 - r_ref, 6 - c_ref};
    }
}

void construct() {
    string s[7];
    for (int i = 0; i < 7; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            auto [r, c] = coords(i, j);
            rows[i][j] = (s[r][c] == 'W' ? 1 : (s[r][c] == '.' ? 0 : -1));
            swap(r, c);
            cols[i][j] = (s[r][c] == 'W' ? 1 : (s[r][c] == '.' ? 0 : -1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    construct();

    for (int i = 0; i < 8; i++) {
        if (has_double_mill(rows, i) || has_double_mill(cols, i)) {
            cout << "double mill" << "\n";
            return 0;
        }
    }

    cout << "no double mill" << "\n";
}