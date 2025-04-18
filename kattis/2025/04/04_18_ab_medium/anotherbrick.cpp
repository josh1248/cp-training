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

    int h, w, n; cin >> h >> w >> n;
    vi bricks(n);
    rep(i, 0, n) cin >> bricks[i];
    int heightleft = h;
    int widthleft = w;
    rep(i, 0, n) {
        if (bricks[i] > widthleft) {
            cout << "NO\n";
            return 0;
        }
        widthleft -= bricks[i];
        if (widthleft == 0) {
            heightleft--;
            widthleft = w;
            if (heightleft == 0) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

}