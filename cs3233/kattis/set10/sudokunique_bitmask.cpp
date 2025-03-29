#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

struct SudokuSolver {
    static const int BLANK = -1;
    int rows[9], cols[9], squares[9], consistent;
    int numSolutions, clues;
    int grid[9][9];
    int its = 0;
    vvi solutionGrid;
    vi zeroes;

    // row, column, square
    tuple<int, int, int> getCoordinates(int cell) {
        int r = cell / 9;
        int c = cell % 9;
        int square = (r / 3) * 3 + (c / 3);
        return {r, c, square};
    }

    // return if placing is consistent
    bool populate(int cell, int num) {
        bool ok = true;
        auto [r, c, square] = getCoordinates(cell);
        
        if (!(cols[c] & (1 << num))) {
            ok = false;
        }
        cols[c] &= (~(1 << num)); // turn off availability

        if (!(rows[r] & (1 << num))) {
            ok = false;
        }
        rows[r] &= (~(1 << num));

        if (!(squares[square] & (1 << num))) {
            ok = false;
        }
        squares[square] &= (~(1 << num));
        if (ok) {
            grid[r][c] = num;
        }
        return ok;
    }

    void unpopulate(int cell, int num) {
        auto [r, c, square] = getCoordinates(cell);
        rows[r] |= (1 << num);
        cols[c] |= (1 << num);
        squares[square] |= (1 << num);
        grid[r][c] = BLANK;
        return;
    }

    bool isAvailable(int r, int c, int square, int num) {
        return (rows[r] & (1 << num)) & (cols[c] & (1 << num)) & (squares[square] & (1 << num));
    }

    bool isLocked(int r, int c, int square) {
        return ((rows[r] & cols[c] & squares[square]) == 0);
    }

    void backtrack(int idx) {
        its++;
        if (numSolutions > 1) return;
        if (idx >= sz(zeroes)) {
            numSolutions++;
            rep(i, 0, 9) {
                rep(j, 0, 9) {
                    solutionGrid[i][j] = grid[i][j];
                }
            }
            return;
        }

        int cell = zeroes[idx];
        auto [r, c, square] = getCoordinates(cell);
        
        if (grid[r][c] != BLANK) {
            backtrack(idx + 1);
            return;
        }

        rep(num, 0, 9) {
            if (!isAvailable(r, c, square, num)) {
                continue;
            }


            populate(cell, num);
            // ensure that no further cells are locked out
            bool locked = false;
            rep(i, r + 1, 9) {
                if (grid[i][c] == BLANK && isLocked(i, c, square)) {
                    locked = true;
                    break;
                }
            }
            if (!locked) {
                rep(i, c + 1, 9) {
                    if (grid[r][i] == BLANK && isLocked(r, i, square)) {
                        locked = true;
                        break;
                    }
                }
            }
            // if (!locked) {
            //     int sr = square / 3, sc = square % 3;
            //     rep(i, 0, 3) {
            //         rep(j, 0, 3) {
            //             int x = sr * 3 + i, y = sc * 3 + j;
            //             if (grid[x][y] == BLANK && isLocked(x, y, square)) {
            //                 locked = true;
            //                 break;
            //             }
            //         }
            //     }
            // }
            if (!locked) {
                backtrack(idx + 1);
            }
            unpopulate(cell, num);
        }
    }

    SudokuSolver(int startGrid[9][9]) {
        rep(i, 0, 9) {
            rows[i] = cols[i] = squares[i] = ((1 << 9) - 1);
        }
        consistent = true;
        numSolutions = 0;
        clues = 0;
        memcpy(grid, startGrid, 81 * sizeof(int));
        solutionGrid = vvi(9, vi(9));

        rep(i, 0, 9) {
            rep(j, 0, 9) {
                int cell = i * 9 + j;
                if (grid[i][j] == BLANK) {
                    zeroes.push_back(cell);
                    continue;
                }
                clues++;
                if (!populate(cell, grid[i][j])) {
                    consistent = false;
                }
            }
        }

        if (consistent && clues >= 17) {
            backtrack(0);
        }
    }

    void printResult() {
        cout << "Iterations used: " << its << "\n";
        if (!consistent) {
            cout << "Find another job\n";
        } else if (numSolutions > 1 || clues < 17) {
            cout << "Non-unique\n";
        } else if (numSolutions == 0) {
            cout << "Find another job\n";
        } else {
            rep(i, 0, 9) {
                rep (j, 0, 9) {
                    cout << solutionGrid[i][j] + 1 << " ";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int placeholder;
    int grid[9][9];
    while (cin >> placeholder) {
        grid[0][0] = placeholder;
        rep(i, 0, 9) {
            rep (j, 0, 9) {
                if (i == 0 && j == 0) continue;
                cin >> grid[i][j];
            }
        }
        rep(i, 0, 9) {
            rep(j, 0, 9) {
                grid[i][j]--;
            }
        }
        SudokuSolver s(grid);
        s.printResult();
    }
}