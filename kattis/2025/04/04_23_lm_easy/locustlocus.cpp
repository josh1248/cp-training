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
    int best = 1e8;
    rep(i, 0, n) {
        int k, c1, c2; cin >> k >> c1 >> c2;
        best = min(best, k + lcm(c1, c2));
    }
    cout << best << "\n";
}