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

    int t; cin >> t;
    rep(i, 0, t) {
        int num; cin >> num; cout << num << " ";
        int b, n; cin >> b >> n;
        int sq = 0;
        while (n > 0) {
            int r = n % b;
            sq += r * r;
            n /= b;
        }
        cout << sq << "\n";
    }
}