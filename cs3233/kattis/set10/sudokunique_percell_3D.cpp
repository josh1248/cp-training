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
bool availables[9][9][9];
vvi available_cnt;
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
    if (available_cnt[i][j] == 0) return;
    rep(nxtnum, 0, 9) {
        if (!availables[i][j][nxtnum]) continue;
        // commence backtracking
        grid[i][j] = nxtnum;
        set<pi> toRestore;
        bool viable = true;
        
        rep(r, 0, 9) {
            if (grid[r][j] != BLANK) continue; // fixed or provided
            if (r == i) continue; // not yourself

            // can use nxtnum while allowing something in this square
            if (available_cnt[r][j] >= 1 && !availables[r][j][nxtnum]) {
            } else if (available_cnt[r][j] > 1) {
            } else {
                viable = false;
                break;
            }

            // mark it
            if (availables[r][j][nxtnum]) {
                toRestore.emplace(r, j);
                available_cnt[r][j]--;
                availables[r][j][nxtnum] = false;
            }
        }

        if (viable) {
            rep(c, 0, 9) {
                if (grid[i][c] != BLANK) continue; // fixed or provided
                if (c == j) continue; // not yourself
                // can use nxtnum while allowing something in this square
                if ((available_cnt[i][c]) >= 1 && !availables[i][c][nxtnum]) {
                } else if (available_cnt[i][c] > 1) {
                } else {
                    viable = false;
                    break;
                }

                // mark it
                if (availables[i][c][nxtnum]) {
                    toRestore.emplace(i, c);
                    available_cnt[i][c]--;
                    availables[i][c][nxtnum] = false;
                }
            }
        }

        if (viable) {
            rep(r, sr * 3, sr * 3 + 3) {
                rep(c, sc * 3, sc * 3 + 3) {
                    if (grid[r][c] != BLANK) continue; // fixed or provided
                    if (r == i && c == j) continue; // not yourself
                    if (available_cnt[r][c] >= 1 && !available_cnt[r][c]) {
                    } else if (available_cnt[r][c] > 1) {
                    } else {
                        viable = false;
                        break;
                    }

                    if (availables[r][c][nxtnum]) {
                        toRestore.emplace(r, c);
                        available_cnt[r][c]--;
                        availables[r][c][nxtnum] = false;
                    }
                }
            }
        }

        if (viable) {
            backtrack(idx + 1);
        }

        // restore
        for (auto &[x, y]: toRestore) {
            availables[x][y][nxtnum] = true;
            available_cnt[x][y]++;
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
                grid[i][j]--; // to make handling easier
            }
        }

        clues = 0;
        solutionsFound = 0;
        memset(availables, 1, sizeof(availables));
        available_cnt = vvi(9, vi(9, 9));
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

                if (!availables[i][j][num]) {
                    isConsistent = false;
                    break;
                }
                memset(availables[i][j], 0, sizeof(availables[i][j]));
                availables[i][j][num] = true;

                // clear rows and cols
                rep(r, 0, 9) {
                    if (r == i) continue;
                    if (available_cnt[r][j] == 1 && !availables[r][j][num]) {
                        continue;
                    } else if (available_cnt[r][j] > 1) {
                        availables[r][j][num] = false;
                        continue;
                    } else {
                        isConsistent = false;
                        break;
                    }
                }
                rep(c, 0, 9) {
                    if (c == j) continue;
                    if (available_cnt[i][c] == 1 && !availables[i][c][num]) {
                        continue;
                    } else if (available_cnt[i][c] > 1) {
                        availables[i][c][num] = false;
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
                        if (available_cnt[r][c] == 1 && !availables[r][c][num]) {
                            continue;
                        } else if (available_cnt[r][c] > 1) {
                            availables[r][c][num] = false;
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