#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    while (cin >> m) {
        if (m == 0) return 0;
        ll maxused = 0, currwidth = 0, usedheight = 0, maxcurrheight = 0;
        ll w, h;
        while (cin >> w >> h) {
            if (w == -1) break;
            if (currwidth + w > m) {
                usedheight += maxcurrheight;
                currwidth = w;
                maxcurrheight = h;
            } else {
                currwidth += w;
                maxused = max(maxused, currwidth);
                maxcurrheight = max(maxcurrheight, h);
            }
        }
        cout << maxused << " x " << usedheight + maxcurrheight << "\n";
    }
}