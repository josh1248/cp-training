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

    unordered_set<string> seen;
    int n; cin >> n;
    int hit = 0;
    rep(i, 0, n) {
        string t, x; cin >> t >> x;
        if (seen.count(t) > 0) continue;
        seen.insert(t); hit++;
        cout << t << " " << x << "\n";
        if (hit >= 12) return 0;
    }
}