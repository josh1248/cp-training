#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).begin()

vector<bool> taken(300, false);
vvi possible(300);

bool backtrack(int m) {
    if (m == -1) {return true;}
    else if (sz(possible[m]) == 0) {return false;}

    for (auto r: possible[m]) {
        if (taken[r]) {continue;}
        taken[r] = true;
        bool res = backtrack(m - 1);    
        if (res) {
            return true;
        }
        taken[r] = false;
    }
    return false;
};

void solve() {
    int n; cin >> n;
    vvi data(n, vi(n + 1, 0ll));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> data[i][j];
        }
    }

    for (int i = 0; i < 300; i++) possible[i].clear();
    taken.assign(300, false);

    // calculate suffix sums
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            data[i][j] += data[i][j + 1];
            if (data[i][j] < 300ll) {
                possible[data[i][j]].push_back(i);
            }
        }
        possible[0].push_back(i);
    }

    

    int low = 0, high = n - 1;
    while (low < high) {
        int guess = (low + high + 1ll) / 2ll;
        taken.assign(300, false);
        if (backtrack(guess)) {
            low = guess;
        } else {
            high = guess - 1ll;
        }
    }

    cout << low + 1ll << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}