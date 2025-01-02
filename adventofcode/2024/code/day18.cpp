#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int BOUNDS = 71;
const int P1 = 1024;

pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool grid[BOUNDS][BOUNDS];

pair<bool, int> bfs() {
    bool seen[BOUNDS][BOUNDS];
    for (int i = 0; i < BOUNDS; ++i) {
        for (int j = 0; j < BOUNDS; ++j) {
            seen[i][j] = false;
        }
    }
    
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (q.size() > 0) {
        auto [r, c, n] = q.front();
        q.pop();
        for (auto [dr, dc]: dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < BOUNDS && nc >= 0 && nr <= BOUNDS && grid[nr][nc] && !seen[nr][nc]) {
                seen[nr][nc] = true;
                if (nr == BOUNDS - 1 && nc == BOUNDS - 1) {
                    return {true, n + 1};
                } else {
                    q.push({nr, nc, n + 1});
                }
            }
        }
    }
    return {false, -1};
}

int main() {
    ifstream ins("../data/day18.txt");

    if (!ins) {
        return 1;
    }

    bool grid[BOUNDS][BOUNDS];
    for (int i = 0; i < BOUNDS; ++i) {
        for (int j = 0; j < BOUNDS; ++j) {
            grid[i][j] = true;
        }
    }

    int r, c; string s; char t; int i = 0;
    while (getline(ins, s)) {
        stringstream ss(s);
        ss >> c >> t >> r;
        grid[r][c] = false;
        ++i;
        if (i == P1) {
            break;
        }
    }

    cout << "part 1: " << bfs().second << "\n";

    while (getline(ins, s)) {
        stringstream ss(s);
        ss >> c >> t >> r;
        grid[r][c] = false;
        if (!bfs().first) {
            cout << "part 2: " << c << "," << r << "\n";
            break;
        }
    }

    ins.close();
}