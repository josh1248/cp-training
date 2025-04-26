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

    int N, Q; cin >> N >> Q;
    vi companies(N);
    rep(i, 0, N) cin >> companies[i];
    rep(i, 0, Q) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            companies[b - 1] = c;
        } else {
            cout << abs(companies[b - 1] - companies[c - 1]) << "\n";
        }
    }
}