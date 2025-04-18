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

    int n; cin >> n;
    vector<pi> knights(n);
    rep(i, 0, n) {
        int h, s; cin >> h >> s;
        knights[i] = {h, s};
    }

    int currknight = 0;
    rep(i, 1, n) {
        while (true) {
            knights[i].first -= knights[currknight].second;
            if (knights[i].first <= 0) {
                break;
            }
            knights[currknight].first -= knights[i].second;
            if (knights[currknight].first <= 0) {
                currknight = i;
                break;
            }
        }
    }
    cout << currknight + 1 << "\n";
}