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

    int n, k; cin >> n >> k;
    vi hit(k + 1);
    rep(i, 0, n) {
        int x; cin >> x;
        hit[x]++;
    }
    int lo = 1e9;
    rep(i, 1, k + 1) {
        lo = min(lo, hit[i]);
    }
    vi ans;
    rep(i, 1, k + 1) {
        if (hit[i] == lo) ans.push_back(i);
    }
    cout << sz(ans) << "\n";
    for(int i: ans) cout << i << " ";
    cout << "\n";
}