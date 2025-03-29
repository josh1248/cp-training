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
    bool rowTaken[9][9], colTaken[9][9], squareTaken[9][9], consistent;
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
        
        if (colTaken[c][num]) {
            ok = false;
        }
        colTaken[c][num] = true;

        if (rowTaken[r][num]) {
            ok = false;
        }
        rowTaken[r][num] = true;

        if (squareTaken[square][num]) {
            ok = false;
        }
        squareTaken[square][num] = true;
        if (ok) {
            grid[r][c] = num;
        }
        return ok;
    }

    void unpopulate(int cell, int num) {
        auto [r, c, square] = getCoordinates(cell);
        rowTaken[r][num] = false;
        colTaken[c][num] = false;
        squareTaken[square][num] = false;
        grid[r][c] = BLANK;
        return;
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
            if (rowTaken[r][num] || colTaken[c][num] || squareTaken[square][num]) {
                continue;
            }

            populate(cell, num);
            backtrack(idx + 1);
            unpopulate(cell, num);
        }
    }

    SudokuSolver(int startGrid[9][9]) {
        memset(rowTaken, 0, sizeof(rowTaken));
        memset(colTaken, 0, sizeof(colTaken));
        memset(squareTaken, 0, sizeof(squareTaken));
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
        if (!consistent || numSolutions == 0) {
            cout << "Find another job\n";
        } else if (numSolutions > 1 || clues < 17) {
            cout << "Non-unique\n";
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