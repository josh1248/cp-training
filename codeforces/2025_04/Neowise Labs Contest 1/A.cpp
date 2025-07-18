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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int lo = -1, hi = 1;
        vi pos(n, 0);
        rep(i, 0, n - 1) {
            char x; cin >> x;
            if (x == '<') pos[i] = lo--;
            else pos[i] = hi++;
        }
        int offset = -lo;
        cout << offset << " ";
        rep(i, 0, n - 1) cout << offset + pos[i] << " ";
        cout << "\n";
    }
}