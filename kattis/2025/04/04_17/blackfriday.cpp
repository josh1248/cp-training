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
    vi cnts(7, 0), location(7);
    int n; cin >> n;
    rep(i, 0, n) {
        int x; cin >> x;
        cnts[x]++;
        location[x] = i;
    }
    for (int i = 6; i >= 1; i--) {
        if (cnts[i] == 1) {
            cout << location[i] + 1;
            return 0;
        }
    }
    cout << "none\n";
}