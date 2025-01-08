#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n; vector<vi> v;
    cin >> r >> c;

    string m[r]; int flood[r][c];
    for (int i = 0; i < r; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            flood[i][j] = -1;
        }
    }

    // bfs all possible regions
    int region = 0;
    queue<pi> q;
    pi d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (flood[i][j] == -1) {
                q = queue<pi>();
                region++;
                q.push({i, j});
                flood[i][j] = region;
                while (q.size() > 0) {
                    auto [a, b] = q.front();
                    q.pop();
                    for (auto [dx, dy]: d) {
                        int nx = a + dx;
                        int ny = b + dy;
                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                            continue;
                        }
                        if (flood[nx][ny] != -1 || m[nx][ny] != m[i][j]) {
                            continue;
                        }
                        flood[nx][ny] = region;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    cin >> n;
    int r1, c1, r2, c2;
    for (int i = 0; i < n; i++) {
        cin >> r1 >> c1 >> r2 >> c2;

        if (flood[r1-1][c1-1] == flood[r2-1][c2-1]) {
            if (m[r1-1][c1-1] == '1') {
                cout << "decimal" << "\n";
            } else {
                cout << "binary" << "\n";
            }
        } else {
            cout << "neither" << "\n";
        }
    }
}