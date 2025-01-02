#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pi;

pi dirs[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main() {
    ifstream ins("../data/day20.txt");
    if (!ins) {
        return 1;
    }

    string s; 
    vector<string> grid;
    pi startc, endc;
    while (getline(ins, s)) {
        grid.push_back(s);

        int spos = s.find('S');
        if (spos != -1) {
            startc = {grid.size() - 1, spos};
        }

        int epos = s.find('E');
        if (epos != -1) {
            endc = {grid.size() - 1, epos};
        }
    }

    // BFS step
    pi notseen = {0, 0};
    vector<vector<pi>> parents(grid.size(), vector<pi>(grid[0].size(), notseen));

    queue<pi> q;
    q.push(startc);
    while (q.size() > 0) {
        auto [r, c] = q.front();
        q.pop();
        for (auto [dr, dc]: dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) {
                continue;
            }

            if ((grid[nr][nc] == '.' || grid[nr][nc] == 'E') && parents[nr][nc] == notseen) {
                parents[nr][nc] = {-dr, -dc};
                q.push({nr, nc});
            }
        }
    }

    vector<pi> chain;
    chain.push_back(endc);
    while (chain[chain.size() - 1] != startc) {
        auto [r, c] = chain[chain.size() - 1];
        auto [dr, dc] = parents[r][c];
        chain.push_back({r + dr, c + dc});
    }

    
    // depths[r][c] represents the picoseconds taken to reach that coordinate without cheats
    vector<vector<int>> depths(grid.size(), vector<int>(grid[0].size(), -1));

    for (int i = 0; i < chain.size(); i++) {
        auto [r, c] = chain[chain.size() - i - 1];
        depths[r][c] = i;
    }

    // 3D matrix
    // let depths[r][c][j] represent the maximum track reachable within j jumps
    int max_jumps = 20;
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(max_jumps + 1, -1)));

    for (int j = 0; j < max_jumps + 1; j++) {
        for (int r = 0; r < depths.size(); r++) {
            for (int c = 0; c < depths[0].size(); c++) {
                int maxSeen = -1;
                for (auto [dr, dc]: dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) {
                        continue;
                    }

                    maxSeen = max(maxSeen, (j == 0 ? depths[nr][nc] : dp[nr][nc][j - 1]));
                }
                dp[r][c][j] = maxSeen;
            }
        }

    }


    int res1 = 0;
    for (int r = 0; r < depths.size(); r++) {
        for (int c = 0; c < depths[0].size(); c++) {
            if (depths[r][c] == -1) {
                continue;
            }

            for (auto [dr, dc]: dirs) {
                int nr = r + 2 * dr;
                int nc = c + 2 * dc;
                if (nr < 0 || nr >= depths.size() || nc < 0 || nc >= depths[0].size()) {
                    continue;
                }

                // if invalid end square, no time savings recorded
                int saved = depths[nr][nc] - depths[r][c] - 2;
                if (saved >= 100) {
                    res1++;
                }
            } 
        }
    }

    int res2 = 0;
    for (int r = 0; r < depths.size(); r++) {
        for (int c = 0; c < depths[0].size(); c++) {
            if (depths[r][c] == -1) {
                continue;   
            }

            int maxSavings = -1;
            for (int j = 2; j < 21; j++) {
                int savings = dp[r][c][j] - depths[r][c] - j;
                maxSavings = max(savings, maxSavings);

            }

            if (maxSavings >= 100) {
                res2++;
            }
        }
    }

    cout << "part 1: " << res1 << "\n";
    cout << "part 2: " << res2 << "\n";

    ins.close();
}