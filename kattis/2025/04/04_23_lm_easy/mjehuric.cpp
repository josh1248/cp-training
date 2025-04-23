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

    vi v(5);
    rep(i, 0, 5) cin >> v[i];
    rep(iter, 0, 5) {
        rep(i, 0, 4) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                for (int x: v) cout << x << " ";
                cout << "\n";
            }
        }
    }
}