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
int rows[8][3];
int cols[8][3];

// double mills must necessarily take place between 2 adjacent rows or between 2 columns (no mixing)
// must check for adjacency here. assume: i < j
bool adjacent[8][8];

// between two adj rows / columns, there is a unique point to check for 1 white / 1 blank
// assume: i < j and i and j are adjacent
pi mill_check(int i, int j) {
    if (i == 0 || i == 1) {
        return {1, 1};
    } else if (i == 2) {
        if (j == 3) {
            return {0, 2};
        } else {
            return {2, 0};
        }
    } else if (i == 3) {
        return {2, 0};
    } else if (i == 4) {
        return {0, 2};
    } else if (i == 5 || i == 6) {
        return {1, 1};
    } else {
        // cout << "WRONG\n";
        return {-1, -1};
    }
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
            rows[i][j] = (s[r][c] == 'W' ? 1 : s[r][c] == '.' ? 0 : -1);
            swap(r, c);
            cols[i][j] = (s[r][c] == 'W' ? 1 : s[r][c] == '.' ? 0 : -1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    construct();
    
    bool flag = false;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (!adjacent(i, j)) {
                continue;
            }
            cout << i << " " << j << " ";

            auto [check_i, check_j] = mill_check(i, j);
            cout << check_i << " " << check_j << "\n";

            // shared point must have 1 blank and 1 white
            if ((rows[i][check_i] == 1 && rows[j][check_j] == 0) ||
                (rows[i][check_i] == 0 && rows[j][check_j] == 1)) {
                // remaining points must be white (check by ensuring exactly 5 whites)
                int counts = 0;
                for (int k = 0; k < 3; k++) {
                    counts += ((rows[i][k] == 1) ? 1 : 0);
                    counts += ((rows[j][k] == 1) ? 1 : 0);
                }

                if (counts == 5) {
                    flag = true;
                }
            }

            

            // columns
            swap(check_i, check_j);

            if ((cols[i][check_i] == 1 && cols[j][check_j] == 0) ||
                (cols[i][check_i] == 0 && cols[j][check_j] == 1)) {
                int counts = 0;
                for (int k = 0; k < 3; k++) {
                    counts += ((cols[i][k] == 1) ? 1 : 0);
                    counts += ((cols[j][k] == 1) ? 1 : 0);
                }

                if (counts == 5) {
                    flag = true;
                }
            }
        }
    }

    cout << (flag ? "" : "no ") << "double mill" << "\n";
}