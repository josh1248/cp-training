#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    map<int, int> used;
    int res = n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (used.count(k) > 0) {
            res = min(res, i - used[k]);
        }
        used[k] = i;
    }
    cout << res << "\n";

}