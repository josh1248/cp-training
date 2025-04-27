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

    int N, L; cin >> N >> L;
    int timenow = 0;
    int posnow = 0;
    rep(i, 0, N) {
        int d, r, g; cin >> d >> r >> g;
        timenow += d - posnow;
        posnow = d;
        if (timenow % (r + g) < r) {
            timenow += r - timenow % (r + g);
        }
    }
    cout << timenow + (L - posnow) << "\n";
}