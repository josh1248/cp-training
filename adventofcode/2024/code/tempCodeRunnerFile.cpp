pair<bool, int> bfs() {
//     queue<tuple<int, int, int>> q;
//     q.push({0, 0, 0});
//     while (q.size() > 0) {
//         auto [r, c, n] = q.front();
//         q.pop();
//         for (auto [dr, dc]: dirs) {
//             int nr = r + dr;
//             int nc = c + dc;
//             if (nr >= 0 && nr < BOUNDS && nc >= 0 && nr <= BOUNDS && grid[nr][nc] && !seen[nr][nc]) {
//                 seen[nr][nc] = true;
//                 if (nr == BOUNDS - 1 && nc == BOUNDS - 1) {
//                     return {true, n + 1};
//                 } else {
//                     q.push({nr, nc, n + 1});
//                 }
//             }
//         }
//     }
//     return {false, -1};
// }