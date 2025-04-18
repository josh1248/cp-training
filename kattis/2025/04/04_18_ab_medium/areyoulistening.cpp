#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

bool has_intersect(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dx = x1 - x2, dy = y1 - y2, sumr = r1 + r2;
    return (dx * dx + dy * dy) < sumr * sumr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, n; cin >> x >> y >> n;
    vector<tuple<int, int, int>> circles;
    rep(i, 0, n) {
        int a, b, r; cin >> a >> b >> r;
        circles.emplace_back(a, b, r);
    }

    int highest = 0;
    rep(i, 0, 10000) {
        int hits = 0;
        rep(j, 0, n) {
            if (has_intersect(get<0>(circles[j]), get<1>(circles[j]), get<2>(circles[j]), x, y, i)) {
                hits++;
            }
        }
        if (hits < 3) {
            highest = i;
        } else {
            break;
        }
    }
    cout << highest << "\n";
}