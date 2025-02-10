#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

const int MAX_P = 13, MAX_SEASONS = 5;
int inf = -1'000'000'000'000;
ll dp_4[MAX_SEASONS][MAX_P][MAX_P][MAX_P][MAX_P];
ll dp_3[MAX_SEASONS][MAX_P][MAX_P][MAX_P];
ll player_data[MAX_P * 4][MAX_SEASONS + 1];

ll dfs_4(int season, int cap, int p1, int p2, int p3, int p4) {
    return 0;
}

ll dfs_3(int season, int cap, int p1, int p2, int p3, vi& players) {
    if (season == cap) {
        return 0;
    }

    ll& ans = dp_3[season][p1][p2][p3];
    if (ans != inf) return ans;
    // consider all trades
    for (int n1: players) {
        for (int n2: players) {
            for (int n3: players) {
                if (n1 == n2 || n1 == n3 || n2 == n3) {
                    continue;
                }

                vi news = {n1, n2, n3};

                ll later = 0;
                // buy required players
                for (int x: news) {
                    // no need rebuy
                    if (x == p1 || x == p2 || x == p3) {
                        continue;
                    }
                    // must buy
                    later -= player_data[x][season];
                }

                // sell not required players
                vi olds = {p1, p2, p3};
                for (int x: olds) {
                    // retained
                    if (x == n1 || x == n2 || x == n3) {
                        continue;
                    }
                    // bye bye
                    later += player_data[x][season] - ((player_data[x][season] + 9) / 10);
                }
                // cout << n1 << "," << n2 << "," << n3 << ": " << later + dfs_3(season + 1, cap, n1, n2, n3, players) << "\n";
                ans = max(ans, later + dfs_3(season + 1, cap, n1, n2, n3, players));
            }
        }
    }
    return ans;
}

void solve() {
    int player_cnt, seasons; cin >> player_cnt >> seasons;
    vvi players(4, vi());
    vi types(player_cnt);
    for (int i = 0; i < player_cnt; i++) {
        cin >> types[i];
        players[types[i]].push_back(i);
        for (int j = 0; j < seasons; j++) {
            cin >> player_data[i][j];    
        }
    }

    vvi inits(4, vi());
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int i = 0; i < 15; i++) {
        int idx; cin >> idx;
        inits[types[idx]].push_back(idx);
    }

    // goalkeeps
    for (int i = 0 ; i < MAX_SEASONS; i++) {
        for (int j = 0; j < MAX_P; j++) {
            for (int k = 0 ; k < MAX_P; k++) {
                for (int l = 0; l < MAX_P; l++) {
                    dp_3[i][j][k][l] = inf;
                }
            }
        }
    }
 
    cout << dfs_3(0, seasons, inits[3][0], inits[3][1], inits[3][2], players[3]) << "\n";
}
// Windows:
// 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17
// 	-fsanitize=undefined,address -o A A.cpp'
// Mac: 'g++-14 -Wall -Wconversion -Wfatal-errors -g -std=c++17 -o A A.cpp'
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}