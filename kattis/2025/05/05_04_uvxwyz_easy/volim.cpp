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

    int timeleft = 210;
    int playernow; cin >> playernow; playernow--;
    int q; cin >> q;
    rep(i, 0, q) {
        int x; char c;
        cin >> x >> c;
        if (timeleft < x) {
            cout << playernow + 1 << "\n";
            return 0;
        }

        timeleft -= x;
        if (c == 'T') {
            playernow = (playernow + 1) % 8;
        }
    }
}