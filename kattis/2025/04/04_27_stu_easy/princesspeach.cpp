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

    int n, y; cin >> n >> y;
    vector<bool> hit(n, false);
    rep(i, 0, y) {
        int x; cin >> x;
        hit[x] = true;
    }
    int found = n;
    rep(i, 0, n) {
        if (!hit[i]) {
            cout << i << "\n";
            found--;
        }
    }
    cout << "Mario got " << found << " of the dangerous obstacles.\n";
}