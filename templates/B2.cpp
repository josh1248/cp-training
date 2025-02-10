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
int l_bound, r_bound;
int inf = -1'000'000'000'000;
ll dp_4[MAX_SEASONS][MAX_P][MAX_P][MAX_P][MAX_P];
ll dp_3[MAX_SEASONS][MAX_P][MAX_P][MAX_P];
ll player_data[49][MAX_SEASONS];

ll dfs_4(int season, int cap, int p1, int p2, int p3, int p4) {
    return 0;
}

ll dfs_3(int season, int cap, int p1, int p2, int p3) {
    if (season == cap) {
        return 0;
    }
    ll& ans = dp_3[season][p1][p2][p3];
    if (ans != inf) return ans;
    // consider all trades
    for (int n1 = l_bound; n1 <= r_bound; n1++) {
        for (int n2 = l_bound; n2 <= r_bound; n2++) {
            for (int n3 = l_bound; n3 <= r_bound; n3++) {
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
                ans = max(ans, later + dfs_3(season + 1, cap, n1, n2, n3));
            }
        }
    }
    return ans;
}

void solve() {
    int player_cnt, seasons; cin >> player_cnt >> seasons;
    for (int i = 0; i < player_cnt; i++) {
        int ptype; cin >> ptype;
        for (int j = 0; j < seasons; j++) {
            cin >> player_data[i][j];
        }
    }
    int a, b, c, d; cin >> a >> b >> c >> d;
    int inits[15];
    for (int i = 0; i < 15; i++) {
        cin >> inits[i];
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
    l_bound = 12, r_bound = player_cnt - 1;
    ll h = dfs_3(0ll, seasons, inits[12], inits[13], inits[14]);
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