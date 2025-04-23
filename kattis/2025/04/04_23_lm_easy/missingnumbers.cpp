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
    int want = 1;
    bool ok = true;
    rep(i, 0, t) {
        int x; cin >> x;
        while (want < x) {
            ok = false;
            cout << want++ << "\n";
        }
        want++;
    }
    if (ok) cout << "good job\n";
}