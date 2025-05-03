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

    int n, q; cin >> n >> q;
    vi v(n);
    rep(i, 0, q) {
        int x; cin >> x;
        if (x == 1) {
            int a, b; cin >> a >> b;
            v[a-1]++;
            v[b-1]++;
        } else {
            int a; cin >> a;
            cout << v[a - 1] << "\n";
        }
    }
}