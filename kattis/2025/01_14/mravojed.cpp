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
ll inf = 10e17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C; cin >> R >> C;
    vector<vector<bool>> grid(R + 2, vector<bool>(C + 2, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char a; cin >> a;
            grid[i + 1][j + 1] = a == 'x';
        }
    }

    // find building 1 by searching for top left corner
    int b1_x, b1_y, b1_size;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (grid[i][j] == 1) {
                int r_allowance = 0, c_allowance = 0;
                int check = i;
                while (grid[check][j]) {
                    check++;
                    r_allowance++;
                }
                check = j;
                while (grid[i][check]) {
                    check++;
                    c_allowance++;
                }
                b1_size =  min(r_allowance, c_allowance);
                cout << i << " " << j << " " << b1_size << "\n";
                b1_x = i; b1_y = j;
                goto done1;
            }
        }
    }
    done1:

    // to prevent clash, start from bottom right
    bool flag = false;
    for (int i = R; i >= 1; i--) {
        for (int j = C; j >= 1; j--) {
            if (flag) {
                continue;
            }

            if (grid[i][j] && (i < b1_x || (i >= b1_x + b1_size) || j < b1_y || (j >= b1_y + b1_size))) {
                flag = true;
                // "fresh" edge may either be bottom right or bottom left
                int r_allowance = 0, c_allowance = 0;
                int check = i;
                while (grid[check][j]) {
                    check--;
                    r_allowance++;
                }
                check = j;
                while (grid[i][check]) {
                    check--;
                    c_allowance++;
                }
                int side_len = min(r_allowance, c_allowance);
                
                // consider bottom left
                int r_alt = 0, c_alt = 0;
                check = i;
                while (grid[check][j]) {
                    check--;
                    r_alt++;
                }
                check = j;
                while (grid[i][check]) {
                    check++;
                    c_alt++;
                }
                int side_len_alt = min(r_alt, c_alt);

                if (side_len >= side_len_alt) {
                    cout << i - side_len + 1 << " " << j - side_len + 1 << " " << side_len << "\n";
                } else {
                    cout << i - side_len_alt + 1 << " " << j << " " << side_len_alt << "\n";
                }
            }
        }
    }

    if (!flag) {
        cout << b1_x << " " << b1_y << " " << b1_size << "\n";
    }
}