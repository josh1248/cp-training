#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

void solve() {
    int N, M, K; cin >> N >> M >> K;

    // always optimal to have M + 1 copies of a number
    // 0 1 ... n 0 1 .... n
    // board cannot cover up at least 1 streak

    // no choice, go from 0 to K - 1, and leftovers for last streak which becomes MEX
    if ((M + 1) * K >= N) {
        rep(i, 0, M) {
            rep(j, 0, K) {
                cout << j << " ";
            }
        }

        rep(i, 0, N - M * K) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }


    // else, we can pad M + 1 copies of 0 to K - 1, and distribute the rest
    int fullstreakBoards = N / (M + 1);
    rep(i, 0, M + 1) {
        rep(j, 0, fullstreakBoards) {
            cout << j << " ";
        }
    }

    // leftovers
    rep(i, 0, N - fullstreakBoards * (M + 1)) {
        cout << 12345 << " "; 
    }
    cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}