#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi seen(n, false);
        int acc = 0;
        rep(i, 0, n) {
            int x; cin >> x;
            if (!seen[x - 1]) {
                seen[x - 1] = true;
                acc++;
            }
        }
        cout << acc << "\n";
    }
}