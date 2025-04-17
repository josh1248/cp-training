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

    int r, n; cin >> r >> n;
    vector<bool> booked(r, false);
    rep(i, 0, n) {
        int x; cin >> x;
        booked[x - 1] = true;
    }
    rep(i, 0, r) {
        if (!booked[i]) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "too late\n";
}