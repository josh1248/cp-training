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

    int c; cin >> c;
    vvi v(c);
    rep(i, 0, 3) {
        rep(j, 0, c) {
            int x; cin >> x;
            v[j].push_back(x);
        }
    }
    rep(i, 0, c) {
        sort(all(v[i]));
        cout << v[i][1] << " ";
    }
    cout << "\n";
}