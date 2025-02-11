#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p; cin >> n >> m >> p;
    int h = n;
    for (int i = 0; i < m; i++) {
        int attack; cin >> attack;
        if (attack >= n) {
            cout << "next time\n";
            return 0;
        }

        if (h - attack > 0) {
            h -= attack;
            continue;
        }

        int req_potions = 1 + (attack - h) / 20;
        h = min(n, h + req_potions * 20) - attack;
        p -= req_potions;
    }
    cout << (p >= 0 ? "champion" : "next time") << "\n";
    return 0;
}