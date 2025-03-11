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
    int t; cin >> t;
    while (t--) {
        ll N, K; cin >> N >> K;
        if (K % 2 == 0) {
            // send to 2nd last cell, then last cell
            // only the 2nd last guy is sad
            rep(i, 0, N - 2) {
                cout << N - 1 << " ";
            }
            cout << N << " " << N - 1 << "\n";
        } else {
            // send to last cell, last cell TP to 2nd last
            // only last guy is sad
            rep(i, 0, N - 2) {
                cout << N << " ";
            }
            cout << N << " " << N - 1 << "\n";
        }
    }
}