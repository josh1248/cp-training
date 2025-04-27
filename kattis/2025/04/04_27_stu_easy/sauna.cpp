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

    int intervals; int lo, hi;
    cin >> intervals >> lo >> hi;
    rep(i, 0, intervals - 1) {
        int a, b; cin >> a >> b;
        if (hi < a || b < lo) {
            cout << "bad news\n";
            return 0;
        }
        lo = max(lo, a), hi = min(hi, b);
    } 
    cout << hi - lo + 1 << " " << lo << "\n";
}