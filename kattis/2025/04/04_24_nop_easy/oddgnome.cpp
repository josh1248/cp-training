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
    while (t--) {
        int x; cin >> x;
        vi v(x);
        rep(i, 0, x) cin >> v[i];
        rep(i, 0, x - 2) {
            if (v[i] < v[i + 2]) {
                if (v[i + 1] > v[i + 2] || v[i] > v[i + 1]) {
                    cout << i + 2 << "\n";
                    break;
                }
            }
        }
    }

    
}