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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vi arr(N + 1);
    vi pos(N + 1);
    int x;
    rep(i, 1, N + 1) {
        cin >> x;
        arr[i] = x;
        pos[x] = i;
    }

    int AM[N][N];
    rep(i, 1, N + 1) {
        rep(j, i + 1, N + 1) {
            AM[i][j] = abs(pos[i] - pos[j]);
        }
    }
    
    int acc = 0;
    // MST(0, i) -> MST(0, i - 1) + min(AM[x][i]) for all x < i
    // Iff for all gaps, number of parents of gap equals 0
    rep(v, 2, N + 1) {
        int min_edge = 999;
        rep(u, 1, v) {
            cout << u << " " << v << ": " << AM[u][v] << "\n";
            min_edge = min(min_edge, AM[u][v]);
        }
        cout << min_edge << "\n";
        acc += min_edge;
    }
    cout << acc << "\n";
}