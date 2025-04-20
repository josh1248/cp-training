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

    int a, b, n; cin >> a >> b >> n;
    int cap = (a - b) * 9 / 10;
    rep(i, 0, n) {
        int x; cin >> x;
        cap -= x;
    }
    cout << cap << "\n";
}