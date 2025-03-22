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
#define rep(i, a, b) for (int i = a; i < (b); i++)

vi monsters, monsterhp;
vi mines;
vector<bool> mine_used, monster_killed;
// store monster position of "clashes", equidistant to both mines
vvi clashes;

int reqs(int pos, int idx, int hp) {
    // bin search right mine
    vi::iterator it_right = lower_bound(all(mines), pos);
    int dist_right = (it_right == mines.end() ? 2e9 : (*it_right) - pos);
    int dist_left = (it_right == mines.begin() ? 2e9 : pos - (*(it_right - 1)));

    // bin search right mine
    if (dist_left < hp && dist_left < dist_right) {
        mine_used[distance(mines.begin(), it_right) - 1] = true;
        return dist_left;
    } else if (dist_right < hp && dist_right < dist_left) {
        mine_used[distance(mines.begin(), it_right)] = true;
        return dist_right;
    } else if (dist_left == dist_right && dist_left < hp) {
        // check if already used
        if (mine_used[distance(mines.begin(), it_right)] || mine_used[distance(mines.begin(), it_right) - 1]) {
            return dist_left;
        }

        // otherwise, return -1 to indicate a clash, and store the clash
        clashes[distance(mines.begin(), it_right)].push_back(idx);
        clashes[distance(mines.begin(), it_right) - 1].push_back(idx);
        return -1;
    } else {
        return hp;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    monsters = vi(n), monsterhp = vi(n), monster_killed = vector<bool>(n, false);
    mines =  vi(k), mine_used = vector<bool>(k, false), clashes = vvi(k);
    rep(i, 0, n) {
        cin >> monsters[i] >> monsterhp[i];
    }
    rep(i, 0, k) {
        cin >> mines[i];
    }
    sort(all(mines));

    ll acc = 0;
    rep(i, 0, n) {
        int x = reqs(monsters[i], i, monsterhp[i]);
        if (x != -1) {
            acc += x;
            monster_killed[i] = true;
        }
    }
    rep(i, 0, k) {
        if (mine_used[i]) acc++;
    }

    // explode clashes next to mines
    rep(i, 0, k) {
        if (mine_used[i] == true) {

            // add clashing monsters
            for (int j: clashes[i]) {
                if (!monster_killed[j]) {
                    acc += abs(monsters[j] - mines[i]);
                    monster_killed[j] = true;
                }
            }
        } 
    }

    // now, handle the problematic cases - equidistant to 2 unexploded mines
    rep(i, 0, k) {
        if (!mine_used[i]) {
            // if there are 2 clashes, always optimal to explode (iterated left to right)
            // if 1 clash, may not be - need to wait for next loop
            int left = 0;
            for (int j: clashes[i]) {
                if (!monster_killed[j]) {
                    left++;
                }
            }
            if (left == 2) {
                mine_used[i] = true;
                acc++;
                for (int j: clashes[i]) {
                    if (!monster_killed[j]) {
                        acc += abs(monsters[j] - mines[i]);
                        monster_killed[j] = true;
                    }
                }
            }
        }
    }

    // explode clashes next to mines
    rep(i, 0, k) {
        if (mine_used[i] == true) {
            // add clashing monsters
            for (int j: clashes[i]) {
                if (!monster_killed[j]) {
                    acc += abs(monsters[j] - mines[i]);
                    monster_killed[j] = true;
                }
            }
        } 
    }

    // now, only 1 clash results (mines only have at most 1 clash left), pick either
    rep(i, 0, k) {
        if (mine_used[i] == false) {
            int x = 0;
            // add clashing monsters
            for (int j: clashes[i]) {
                if (!monster_killed[j]) {
                    x++;
                }
            }
            if (x > 0) {
                acc++;
                for (int j: clashes[i]) {
                    if (!monster_killed[j]) {
                        acc += abs(monsters[j] - mines[i]);
                        monster_killed[j] = true;
                    }
                }
            }
        }
    }

    // and finally, time to finish off those whose mines at both sides have not been used
    rep(i, 0, k) {
        if (mine_used[i] == false) {
            int left = 0;
            // add clashing monsters
            for (int j: clashes[i]) {
                if (!monster_killed[j]) {
                    left++;
                }
            }
            if (left > 0) {
                acc++;
                for (int j: clashes[i]) {
                    if (!monster_killed[j]) {
                        monster_killed[j] = true;
                        acc += abs(monsters[j] - mines[i]);
                    }
                }
            }
        }
    }

    cout << acc << "\n";
    return 0;
}