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
    vector<bool> hit(365, false);
    rep(i, 0, n) {
        int lo, hi; cin >> lo >> hi;
        --lo, --hi;
        rep(j, lo, hi + 1) hit[j] = true;
    }

    cout << count_if(all(hit), [](bool b){return b;}) << "\n";
}