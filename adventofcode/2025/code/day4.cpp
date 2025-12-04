#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ifstream ins("../data/day4.txt");
    if (!ins) return 1;
    
    // pad with .
    string s; vector<string> grid;
    ins >> s;
    grid.push_back(string(s.size() + 2, '.'));
    grid.push_back("." + s + ".");
    while (ins >> s) {
        grid.push_back("." + s + ".");
    }
    grid.push_back(string(s.size() + 2, '.'));

    ins.close();

    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> surroundings(R, vector<int>(C));
    vector<pair<int,int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int r = 1; r < R - 1; r++) {
        for (int c = 1; c < C - 1; c++) {
            if (grid[r][c] == '@') {
                for (auto& [dr, dc]: dirs) {
                    surroundings[r + dr][c + dc]++;
                }
            }
        }
    }

    int part1 = 0, part2 = 0;
    for (int r = 1; r < R - 1; r++) {
        for (int c = 1; c < C - 1; c++) {
            if (grid[r][c] == '@' && surroundings[r][c] <= 3) {
                part1++;
            }
        }
    }

    function<void(int, int)> dfs = [&](int r, int c) {
        if (grid[r][c] == '@' && surroundings[r][c] <= 3) {
            part2++;
            grid[r][c] = 'x';
            for (auto& [dr, dc]: dirs) {
                surroundings[r + dr][c + dc]--;
            }
            for (auto& [dr, dc]: dirs) {
                dfs(r + dr, c + dc);
            }
        }
    };

    for (int r = 1; r < R - 1; r++) {
        for (int c = 1; c < C - 1; c++) {
            dfs(r, c);
        }
    }

    cout << "part 1: " << part1 << "\n";
    cout << "part 2: " << part2 << "\n";
}