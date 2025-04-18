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

    int t; cin >> t;
    rep(i, 0, t) {
        int s, d; cin >> s >> d;
        if (s < 0 || d < 0 || s < d || ((s + d) % 2 == 1)) {
            cout << "impossible\n";
            continue;
        }
        cout << (s + d) / 2 << " " << (s - d) / 2 << "\n";
    }
}