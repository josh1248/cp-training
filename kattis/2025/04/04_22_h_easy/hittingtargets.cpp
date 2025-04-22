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
    int n; cin >> n;
    vector<tuple<int,int,int,int>> rects;
    vector<tuple<int,int,int>> circs;
    string t;
    rep(i, 0, n) {
        cin >> t;
        if (t == "rectangle") {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            rects.emplace_back(x1,y1,x2,y2);
        } else {
            int x, y, r; cin >> x >> y >> r;
            circs.emplace_back(x, y, r);
        }
    }
    int q; cin >> q;
    rep(i, 0, q) {
        int hits = 0;
        int x, y; cin >> x >> y;
        for (auto& [x1,y1,x2,y2]: rects) {
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) hits++;
        }
        for (auto& [x1,y1,r]: circs) {
            if (pow(x - x1, 2) + pow(y - y1, 2) <= pow(r, 2)) hits++;
        }
        cout << hits << "\n";
    }
}