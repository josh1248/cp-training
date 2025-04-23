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

    vi hits(400001);
    rep(i, 1, 100) {
        rep(j, i, 100) {
            int res = i * i * i + j * j * j;
            if (res <= 400000) hits[res]++;
        }
    }
    int n; cin >> n;
    for (int i = n; i >= 1; i--) {
        if (hits[i] > 1) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "none\n";
    return 0;
}