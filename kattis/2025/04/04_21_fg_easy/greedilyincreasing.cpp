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

    int n; cin >> n;
    vi v(n);
    rep(i, 0, n) cin >> v[i];
    vi res;
    int curr = -1;
    rep(i, 0, n) {
        if (v[i] > curr) {
            res.push_back(v[i]);
            curr = v[i];
        }
    }
    cout << sz(res) << "\n";
    for (int i: res) cout << i << " ";
    cout << "\n";
    return 0;
}