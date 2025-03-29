#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

const int BLANK = -1;
int grid[9][9];
int clues = 0;
vvi availables;
vector<pi> blanks;
int solutionGrid[9][9];
int solutionsFound;

void backtrack(int idx) {
    if (solutionsFound > 1) return;
    if (idx >= sz(blanks)) {
        solutionsFound++;
        copy(&grid[0][0], &grid[0][0] + 81, &solutionGrid[0][0]);
        return;
    }

    auto [i, j] = blanks[idx];
    int sr = i / 3, sc = j / 3;
    int s = availables[i][j];
    if (popcount<ull>(s) == 0) return;
    // speedup for unique solution remaining
    if (popcount<ull>(s) == 1) {
        int nxtnum = countr_zero<ull>(s);
        grid[i][j] = nxtnum;
        set<pi> toRestore;
        rep(r, 0, 9) {
            if (grid[r][j] != BLANK || r == i) continue;
            if (availables[r][j] & (1 << nxtnum)) {
                toRestore.emplace(r, j);
            }
            availables[r][j] &= (~(1 << nxtnum));
        }
        rep(c, 0, 9) {
            if (grid[i][c] != BLANK || c == j) continue;
            if(availables[i][c] & (1 << nxtnum)) {
                toRestore.emplace(i, c);
            }
            availables[i][c] &= (~(1 << nxtnum));
        }
        rep(r, sr * 3, sr * 3 + 3) {
            rep(c, sc * 3, sc * 3 + 3) {
                if (grid[r][c] != BLANK) continue; // fixed or provided
                if (r == i && c == j) continue; // not yourself
                if (availables[r][c] & (1 << nxtnum)) {
                    toRestore.emplace(r, c);
                }
                availables[r][c] &= (~(1 << nxtnum));
            }
        }
        backtrack(idx + 1);
        // restore
        for (auto &[r, c]: toRestore) {
            availables[r][c] |= (1 << nxtnum);
        }
        grid[i][j] = BLANK;
        return;
    }

    while (s > 0) {
        bool possible = true;
        int nxtnumpow = (s & (-s));
        int nxtnum = countr_zero<ull>(nxtnumpow);
        s -= nxtnumpow;
        rep(r, 0, 9) {
            if (grid[r][j] != BLANK) continue; // fixed or provided
            if (r == i) continue; // not yourself
            // can use nxtnum while allowing something in this square
            if (popcount<ull>(availables[r][j]) >= 1 && (availables[r][j] & (1 << nxtnum)) == 0) {
                continue;
            } else if (popcount<ull>(availables[r][j]) > 1) {
                continue;
            } else {
                possible = false;
                break;
            }
        }
        rep(c, 0, 9) {
            if (grid[i][c] != BLANK) continue; // fixed or provided
            if (c == j) continue; // not yourself
            // can use nxtnum while allowing something in this square
            if (popcount<ull>(availables[i][c]) >= 1 && (availables[i][c] & (1 << nxtnum)) == 0) {
                continue;
            } else if (popcount<ull>(availables[i][c]) > 1) {
                continue;
            } else {
                possible = false;
                break;
            }
        }
        rep(r, sr * 3, sr * 3 + 3) {
            rep(c, sc * 3, sc * 3 + 3) {
                if (grid[r][c] != BLANK) continue; // fixed or provided
                if (r == i && c == j) continue; // not yourself
                if (popcount<ull>(availables[r][c]) >= 1 && (availables[r][c] & (1 << nxtnum)) == 0) {
                    continue;
                } else if (popcount<ull>(availables[r][c]) > 1) {
                    continue;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (!possible) {
            continue;
        }

        // OK: commence backtracking
        grid[i][j] = nxtnum;
        set<pi> toRestore;
        rep(r, 0, 9) {
            if (grid[r][j] != BLANK || r == i) continue;
            if(availables[r][j] & (1 << nxtnum)) {
                toRestore.emplace(r, j);
            }
            availables[r][j] &= (~(1 << nxtnum));
        }
        rep(c, 0, 9) {
            if (grid[i][c] != BLANK || c == j) continue;
            if(availables[i][c] & (1 << nxtnum)) {
                toRestore.emplace(i, c);
            }
            availables[i][c] &= (~(1 << nxtnum));
        }
        rep(r, sr * 3, sr * 3 + 3) {
            rep(c, sc * 3, sc * 3 + 3) {
                if (grid[r][c] != BLANK) continue; // fixed or provided
                if (r == i && c == j) continue; // not yourself
                if (availables[r][c] & (1 << nxtnum)) {
                    toRestore.emplace(r, c);
                }
                availables[r][c] &= (~(1 << nxtnum));
            }
        }
        backtrack(idx + 1);
        // restore
        for (auto &[x, y]: toRestore) {
            availables[x][y] |= (1 << nxtnum);
        }
        grid[i][j] = BLANK;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int placeholder;
    while (cin >> placeholder) {
        grid[0][0] = placeholder - 1;
        rep(i, 0, 9) {
            rep (j, 0, 9) {
                if (i == 0 && j == 0) continue;
                cin >> grid[i][j];
                grid[i][j]--; // to make bit manipulation easier
            }
        }

        clues = 0;
        solutionsFound = 0;
        // bitmask
        availables = vvi(9, vi(9, (1 << 9) - 1));
        blanks.clear();
        bool isConsistent = true;
        rep(i, 0, 9) {
            if (!isConsistent) break;
            rep(j, 0, 9) {
                int num = grid[i][j];
                if (num == BLANK) {
                    blanks.emplace_back(i, j);
                    continue;
                }
                clues++;

                if ((availables[i][j] & (1 << num)) == 0) {
                    isConsistent = false;
                    break;
                }
                availables[i][j] = (1 << num);

                // clear rows and cols
                rep(r, 0, 9) {
                    if (r == i) continue;
                    if (popcount<ull>(availables[r][j]) == 1 && (availables[r][j] & (1 << num)) == 0) {
                        continue;
                    } else if (popcount<ull>(availables[r][j]) > 1) {
                        availables[r][j] &= (~(1 << num));
                        continue;
                    } else {
                        isConsistent = false;
                        break;
                    }
                }
                rep(c, 0, 9) {
                    if (c == j) continue;
                    if ((popcount<ull>(availables[i][c]) == 1) && ((availables[i][c] & (1 << num)) == 0)) {
                        continue;
                    } else if (popcount<ull>(availables[i][c]) > 1) {
                        availables[i][c] &= (~(1 << num));
                        continue;
                    } else {
                        isConsistent = false;
                        break;
                    }
                }

                // clear square
                int sr = i / 3, sc = j / 3;
                rep(r, sr * 3, sr * 3 + 3) {
                    rep(c, sc * 3, sc * 3 + 3) {
                        if (r == i && c == j) continue;
                        if (popcount<ull>(availables[r][c]) == 1 && (availables[r][c] & (1 << num)) == 0) {
                            continue;
                        } else if (popcount<ull>(availables[r][c]) > 1) {
                            availables[r][c] &= (~(1 << num));
                            continue;
                        } else {
                            isConsistent = false;
                            break;
                        }
                    }
                }
            }
        }
        if (!isConsistent) {
            cout << "Find another job\n\n";
            continue;
        } else if (clues < 17) {
            // https://en.wikipedia.org/wiki/Mathematics_of_Sudoku
            cout << "Non-unique\n\n";
            continue;
        }



        backtrack(0);

        if (solutionsFound == 0) {
            cout << "Find another job\n\n";
        } else if (solutionsFound > 1) {
            cout << "Non-unique\n\n";
        } else {
            rep(i, 0, 9) {
                rep(j, 0, 9) {
                    cout << solutionGrid[i][j] + 1 << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
}